#!/usr/bin/env python
#
# Copyright (C) 2013  Google Inc.
#
# This file is part of YouCompleteMe.
#
# YouCompleteMe is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# YouCompleteMe is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with YouCompleteMe.  If not, see <http://www.gnu.org/licenses/>.

import vim
from ycm.client.base_request import BaseRequest, BuildRequestData, ServerError
from ycm import vimsupport
from ycmd.utils import ToUtf8IfNeeded

def _EnsureBackwardsCompatibility( arguments ):
  if arguments and arguments[ 0 ] == 'GoToDefinitionElseDeclaration':
    arguments[ 0 ] = 'GoTo'
  return arguments


class CommandRequest( BaseRequest ):
  def __init__( self, arguments, completer_target = None ):
    super( CommandRequest, self ).__init__()
    self._arguments = _EnsureBackwardsCompatibility( arguments )
    self._completer_target = ( completer_target if completer_target
                               else 'filetype_default' )
    self._is_goto_command = (
        self._arguments and self._arguments[ 0 ].startswith( 'GoTo' ) )
    self._is_fixit_command = (
        self._arguments and self._arguments[ 0 ].startswith( 'FixIt' ) )
    self._response = None


  def Start( self ):
    request_data = BuildRequestData()
    request_data.update( {
      'completer_target': self._completer_target,
      'command_arguments': self._arguments
    } )
    try:
      self._response = self.PostDataToHandler( request_data,
                                              'run_completer_command' )
    except ServerError as e:
      vimsupport.PostMultiLineNotice( e )


  def Response( self ):
    return self._response

  def RunPostCommandActionsIfNeeded( self ):
    if not self.Done() or not self._response:
      return

    if self._is_goto_command:
      self._HandleGotoResponse()
    elif self._is_fixit_command:
      self._HandleFixitResponse()
    elif 'message' in self._response:
      self._HandleMessageResponse()

  def _HandleGotoResponse( self ):
    if isinstance( self._response, list ):
      defs = [ _BuildQfListItem( x ) for x in self._response ]
      vim.eval( 'setqflist( %s )' % repr( defs ) )
      vim.eval( 'youcompleteme#OpenGoToList()' )
    else:
      vimsupport.JumpToLocation( self._response[ 'filepath' ],
                                  self._response[ 'line_num' ],
                                  self._response[ 'column_num' ] )

  def _HandleFixitResponse( self ):
    if not len( self._response[ 'fixits' ] ):
      vimsupport.EchoText( "No fixits found for current line" )
    else:
      fixit = self._response[ 'fixits' ][ 0 ]

      # We need to track the difference in length, but ensuring we apply fixes
      # in ascending order of insertion point.
      fixit[ 'chunks' ].sort( key = lambda chunk:  (
        str(chunk[ 'range' ][ 'start' ][ 'line_num' ])
        + ','
        + str(chunk[ 'range' ][ 'start' ][ 'column_num' ])
      ))

      # Remember the line number we're processing. Negative line number means we
      # haven't processed any lines yet (by nature of being not equal to any
      # real line number).
      last_line = -1

      # Counter of changes applied, so the user has a mental picture of the
      # undo history this change is creating.
      num_fixed = 0
      line_delta = 0
      for chunk in fixit[ 'chunks' ]:
        if chunk[ 'range' ][ 'start' ][ 'line_num' ] != last_line:
          # If this chunk is on a different line than the previous chunk,
          # then ignore previous deltas (as offsets won't have changed).
          last_line = chunk[ 'range' ][ 'end' ][ 'line_num' ]
          char_delta = 0

        (new_line_delta, new_char_delta) = vimsupport.ReplaceChunk(
                                          chunk[ 'range' ][ 'start' ],
                                          chunk[ 'range' ][ 'end' ],
                                          chunk[ 'replacement_text' ],
                                          line_delta, char_delta )
        line_delta += new_line_delta
        char_delta += new_char_delta

        num_fixed = num_fixed + 1

      vimsupport.EchoTextVimWidth("FixIt applied " 
                                  + str(num_fixed) 
                                  + " changes")

  def _HandleMessageResponse( self ):
    vimsupport.EchoText( self._response[ 'message' ] )

def SendCommandRequest( arguments, completer ):
  request = CommandRequest( arguments, completer )
  # This is a blocking call.
  request.Start()
  request.RunPostCommandActionsIfNeeded()
  return request.Response()


def _BuildQfListItem( goto_data_item ):
  qf_item = {}
  if 'filepath' in goto_data_item:
    qf_item[ 'filename' ] = ToUtf8IfNeeded( goto_data_item[ 'filepath' ] )
  if 'description' in goto_data_item:
    qf_item[ 'text' ] = ToUtf8IfNeeded( goto_data_item[ 'description' ] )
  if 'line_num' in goto_data_item:
    qf_item[ 'lnum' ] = goto_data_item[ 'line_num' ]
  if 'column_num' in goto_data_item:
    qf_item[ 'col' ] = goto_data_item[ 'column_num' ] - 1
  return qf_item

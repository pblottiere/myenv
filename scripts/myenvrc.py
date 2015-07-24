#-------------------------------------------------------------------------------
# imports
#-------------------------------------------------------------------------------
import os
import sys
import fileinput

sys.path.insert(0, ".")
import confoption

#-------------------------------------------------------------------------------
# const, paths, ...
#-------------------------------------------------------------------------------
MYENVRC=".myenvrc"
BASHRC=".bashrc"
PART="MYENV"

#===============================================================================
#
# Functions
#
#===============================================================================
#-------------------------------------------------------------------------------
# myenvrc
#-------------------------------------------------------------------------------
def myenvrc():
    home = os.path.expanduser("~")
    return os.path.join(home, MYENVRC)

#-------------------------------------------------------------------------------
# bashrc
#-------------------------------------------------------------------------------
def bashrc():
    home = os.path.expanduser("~")
    return os.path.join(home, BASHRC)

#-------------------------------------------------------------------------------
# create
#-------------------------------------------------------------------------------
def create():
    rc = confoption.create(myenvrc())
    if rc == True:
        confoption.part_create(bashrc(), PART)
        confoption.part_add(bashrc(), PART, "source %s" % myenvrc())

#-------------------------------------------------------------------------------
# delete
#-------------------------------------------------------------------------------
def delete():
    confoption.delete(myenvrc())
    confoption.part_delete(bashrc(), PART)

#-------------------------------------------------------------------------------
# part_add
#-------------------------------------------------------------------------------
def part_add(part, data):
    confoption.part_add(myenvrc(), part, data)

#-------------------------------------------------------------------------------
# part_create
#-------------------------------------------------------------------------------
def part_create(part):
    confoption.part_create(myenvrc(), part)

#-------------------------------------------------------------------------------
# part_delete
#-------------------------------------------------------------------------------
def part_delete(part):
    rc = confoption.create(myenvrc())
    if rc == True:
        confoption.part_delete(myenvrc(), part)

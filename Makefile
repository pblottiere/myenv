#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/scripts

#------------------------------------------------------------------------------
# install
#------------------------------------------------------------------------------
install-myenvrc:
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.create()"

install-vim:
	@cd vim && make install

install-git:
	@cd git && make install

install-urxvt:
	@cd urxvt && make install

install-svn:
	@cd svn && make install

install-vmail:
	@cd vmail && make install

install: install-myenvrc install-vim install-git install-urxvt install-svn install-vmail

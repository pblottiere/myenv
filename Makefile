#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/scripts

#------------------------------------------------------------------------------
# update
#------------------------------------------------------------------------------
update-vim:
	@cd vim && make update

update-git:
	@cd git && make update

update-urxvt:
	@cd urxvt && make update

update-svn:
	@cd svn && make update

update: update-vim update-git update-urxvt update-svn

#------------------------------------------------------------------------------
# install
#------------------------------------------------------------------------------
install-myenvrc:
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.create()"

install-vim:
	@cd vim && make install

install-git:
	@cd git && make install

install-fluxbox:
	@cd fluxbox && make install

install-urxvt:
	@cd urxvt && make install

install-svn:
	@cd svn && make install

install: install-myenvrc install-vim install-git install-fluxbox install-urxvt install-svn

#------------------------------------------------------------------------------
# uninstall
#------------------------------------------------------------------------------
uninstall-myenvrc:
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.delete()"

uninstall-vim:
	@cd vim && make uninstall

uninstall-git:
	@cd git && make uninstall

uninstall-fluxbox:
	@cd fluxbox && make uninstall

uninstall-urxvt:
	@cd urxvt && make uninstall

uninstall-svn:
	@cd svn && make uninstall

uninstall: uninstall-myenvrc uninstall-vim uninstall-git uninstall-fluxbox uninstall-urxvt uninstall-svn

#------------------------------------------------------------------------------
# clean
#------------------------------------------------------------------------------
clean-vim:
	@cd vim && make clean

clean-git:
	@cd git && make clean

clean-urxvt:
	@cd urxvt && make clean

clean-svn:
	@cd svn && make clean

clean: clean-vim clean-git clean-urxvt clean-svn

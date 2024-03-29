#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/tools

#------------------------------------------------------------------------------
# install
#------------------------------------------------------------------------------
install-myenvrc:
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.create()"

install-vim:
	@cd vim && make install

install-git:
	@cd git && make install

install: install-myenvrc install-vim install-git

dark:
	@cd terminology && make dark
	@cd tools && make dark

light:
	@cd terminology && make light
	@cd tools && make light

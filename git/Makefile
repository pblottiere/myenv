#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#-------------------------------------------------------------------------------
# update
#-------------------------------------------------------------------------------
update:
	cp $(HOME)/.gitconfig dot_gitconfig

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall:
	rm -f $(HOME)/.gitconfig
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.remove_part('GIT')"

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install:
	@if [ -f $(HOME)/.gitconfig ]; \
	then \
		mv $(HOME)/.gitconfig $(HOME)/.gitconfig_$(NOW); \
	fi
	cp dot_gitconfig $(HOME)/.gitconfig

	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.remove_part('GIT')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.init_part('GIT')"

#-------------------------------------------------------------------------------
# clean
#-------------------------------------------------------------------------------
clean:
	find $(HOME)/.* -maxdepth 1 -type f -name ".gitconfig_*_*_*_*_*_*" | xargs rm -f

#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#-------------------------------------------------------------------------------
# update
#-------------------------------------------------------------------------------
update:
	@echo -n "Update 'git' configuration..."
	@cp $(HOME)/.gitconfig dot_gitconfig
	@echo ": done"

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall:
	@echo -n "Uninstall 'git' configuration..."
	@rm -f $(HOME)/.gitconfig
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('GIT')"
	@echo ": done"

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install:
	@echo -n "Install 'git' configuration..."
	@if [ -f $(HOME)/.gitconfig ]; \
	then \
		mv $(HOME)/.gitconfig $(HOME)/.gitconfig_$(NOW); \
	fi
	@cp dot_gitconfig $(HOME)/.gitconfig
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('GIT')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_create('GIT')"
	@echo ": done"

#-------------------------------------------------------------------------------
# clean
#-------------------------------------------------------------------------------
clean:
	@echo -n "Clean 'git' configuration..."
	@find $(HOME)/.* -maxdepth 1 -type f -name ".gitconfig_*_*_*_*_*_*" | xargs rm -f
	@echo ": done"

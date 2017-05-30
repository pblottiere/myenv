#------------------------------------------------------------------------------
# const, paths
#------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#------------------------------------------------------------------------------
# all
#------------------------------------------------------------------------------
all: install

#------------------------------------------------------------------------------
# update
#------------------------------------------------------------------------------
update:
	@echo -n "Update 'git' configuration..."
	@cp $(HOME)/.gitconfig dot_gitconfig
	@cp $(HOME)/.gitcolor dot_gitcolor
	@cp $(HOME)/.gitcompletion dot_gitcompletion
	@echo ": done"

#------------------------------------------------------------------------------
# uninstall
#------------------------------------------------------------------------------
uninstall:
	@echo -n "Uninstall 'git' configuration..."
	@rm -f $(HOME)/.gitconfig
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('GIT')"
	@echo ": done"

#------------------------------------------------------------------------------
# install
#------------------------------------------------------------------------------
install:
	@echo -n "Install 'git' configuration..."
	@if [ -f $(HOME)/.gitconfig ]; \
	then \
		mv $(HOME)/.gitconfig $(HOME)/.gitconfig_$(NOW); \
	fi
	@if [ -f $(HOME)/.gitcolor ]; \
	then \
		mv $(HOME)/.gitcolor $(HOME)/.gitcolor_$(NOW); \
	fi
	@if [ -f $(HOME)/.gitcompletion ]; \
	then \
		mv $(HOME)/.gitcompletion $(HOME)/.gitcompletion_$(NOW); \
	fi
	@cp dot_gitconfig $(HOME)/.gitconfig
	@cp dot_gitcolor $(HOME)/.gitcolor
	@cp dot_gitcompletion $(HOME)/.gitcompletion
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.create()"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('GIT')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_add('GIT', 'source ~/.gitcolor')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_add('GIT', 'source ~/.gitcompletion')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_create('GIT')"
	@echo ": done"

#------------------------------------------------------------------------------
# clean
#------------------------------------------------------------------------------
clean:
	@echo -n "Clean 'git' configuration..."
	@find $(HOME)/.* -maxdepth 1 -type f -name ".gitconfig_*_*_*_*_*_*" | xargs rm -f
	@echo ": done"

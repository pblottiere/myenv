#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#-------------------------------------------------------------------------------
# update
#-------------------------------------------------------------------------------
update:
	@echo -n "Update 'vim' configuration..."
	@cp -r $(HOME)/.vim/* dot_vim/
	@cp $(HOME)/.vimrc dot_vimrc
	@echo ": done"

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall:
	@echo -n "Uninstall 'vim' configuration..."
	@rm -f $(HOME)/.vimrc
	@rm -rf $(HOME)/.vim
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('VIM')"
	@echo ": done"

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install:
	@echo -n "Install 'vim' configuration..."
	@if [ -d $(HOME)/.vim ]; \
	then \
		mv $(HOME)/.vim $(HOME)/.vim_$(NOW); \
	fi
	@cp -r dot_vim $(HOME)/.vim
	@if [ -f $(HOME)/.vimrc ]; \
	then \
		mv $(HOME)/.vimrc $(HOME)/.vimrc_$(NOW); \
	fi
	@cp dot_vimrc $(HOME)/.vimrc
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('VIM')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_create('VIM')"
	@echo ": done"

#-------------------------------------------------------------------------------
# clean
#-------------------------------------------------------------------------------
clean:
	@echo -n "Clean 'vim' configuration..."
	@find $(HOME)/.* -maxdepth 1 -type d -name ".vim_*_*_*_*_*_*" | xargs rm -rf
	@find $(HOME)/.* -maxdepth 1 -type f -name ".vimrc_*_*_*_*_*_*" | xargs rm -f
	@echo ": done"
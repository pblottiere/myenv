#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#-------------------------------------------------------------------------------
# update
#-------------------------------------------------------------------------------
update:
	cp -r $(HOME)/.vim/* dot_vim/
	cp $(HOME)/.vimrc dot_vimrc

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall:
	rm -f $(HOME)/.vimrc
	rm -rf $(HOME)/.vim
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.remove_part('VIM')"

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install:
	@if [ -d $(HOME)/.vim ]; \
	then \
		mv $(HOME)/.vim $(HOME)/.vim_$(NOW); \
	fi
	cp -r dot_vim $(HOME)/.vim

	@if [ -f $(HOME)/.vimrc ]; \
	then \
		mv $(HOME)/.vimrc $(HOME)/.vimrc_$(NOW); \
	fi
	cp dot_vimrc $(HOME)/.vimrc

	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.remove_part('VIM')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.init_part('VIM')"

#-------------------------------------------------------------------------------
# clean
#-------------------------------------------------------------------------------
clean:
	find $(HOME)/.* -maxdepth 1 -type d -name ".vim_*_*_*_*_*_*" | xargs rm -rf
	find $(HOME)/.* -maxdepth 1 -type f -name ".vimrc_*_*_*_*_*_*" | xargs rm -f

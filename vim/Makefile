#------------------------------------------------------------------------------
# const, paths
#------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#------------------------------------------------------------------------------
# all / build plugins
#------------------------------------------------------------------------------
all: build-ycm build-autoclose build-indentline build-tagbar build-spell \
	 build-nerdtree build-syntastic build-snippets build-ultisnips \
	 build-airline build-ctrlp build-airline-themes build-gnupg

build-airline:
	if [ ! -d $(PWD)/dot_vim/bundle/vim-airline ]; \
	then \
		git clone https://github.com/bling/vim-airline \
			$(PWD)/dot_vim/bundle/vim-airline; \
	fi

build-ycm:
	if [ ! -d "$(PWD)/dot_vim/bundle/YouCompleteMe" ]; \
	then \
		git clone https://github.com/Valloric/YouCompleteMe.git \
			$(PWD)/dot_vim/bundle/YouCompleteMe; \
	fi
	cd $(PWD)/dot_vim/bundle/YouCompleteMe && \
		git submodule update --init --recursive
	cd $(PWD)/dot_vim/bundle/YouCompleteMe && python install.py --clang-completer

build-autoclose:
	if [ ! -d $(PWD)/dot_vim/bundle/vim-autoclose ]; \
	then \
		git clone https://github.com/Townk/vim-autoclose \
			$(PWD)/dot_vim/bundle/vim-autoclose; \
	fi

build-gnupg:
	if [ ! -f $(PWD)/dot_vim/plugin/gnupg.vim ]; \
	then \
		git clone https://github.com/jamessan/vim-gnupg \
			$(PWD)/dot_vim/plugin/vim-gnupg; \
		mv $(PWD)/dot_vim/plugin/vim-gnupg/plugin/gnupg.vim \
			$(PWD)/dot_vim/plugin; \
		rm -rf $(PWD)/dot_vim/plugin/vim-gnupg; \
	fi

build-indentline:
	if [ ! -d $(PWD)/dot_vim/bundle/indentLine ]; \
	then \
		git clone https://github.com/Yggdroot/indentLine \
			$(PWD)/dot_vim/bundle/indentLine; \
	fi

build-tagbar:
	if [ ! -d $(PWD)/dot_vim/bundle/Tagbar ]; \
	then \
		git clone https://github.com/vim-scripts/Tagbar \
			$(PWD)/dot_vim/bundle/Tagbar; \
 	fi

build-spell:
	if [ ! -d $(PWD)/dot_vim/spell ]; \
	then \
		wget -P $(PWD)/dot_vim/spell \
			http://ftp.vim.org/vim/runtime/spell/fr.latin1.spl; \
	 	wget  -P $(PWD)/dot_vim/spell \
			http://ftp.vim.org/vim/runtime/spell/fr.latin1.sug; \
		wget  -P $(PWD)/dot_vim/spell \
			http://ftp.vim.org/vim/runtime/spell/fr.utf-8.spl; \
	  	wget  -P $(PWD)/dot_vim/spell \
			http://ftp.vim.org/vim/runtime/spell/fr.utf-8.sug; \
 	fi

build-nerdtree:
	if [ ! -d $(PWD)/dot_vim/bundle/nerdtree ]; \
	then \
		git clone https://github.com/scrooloose/nerdtree.git \
			$(PWD)/dot_vim/bundle/nerdtree; \
 	fi

build-syntastic:
	if [ ! -d $(PWD)/dot_vim/bundle/syntastic ];\
	then \
		git clone https://github.com/scrooloose/syntastic.git \
			$(PWD)/dot_vim/bundle/syntastic; \
	fi

build-snippets:
	if [ ! -d $(PWD)/dot_vim/bundle/vim-snippets ] ;\
	then \
		git clone https://github.com/honza/vim-snippets \
			$(PWD)/dot_vim/bundle/vim-snippets; \
	fi

build-ultisnips:
	if [ ! -d $(PWD)/dot_vim/bundle/ultisnips ];\
	then \
		git clone https://github.com/SirVer/ultisnips \
			$(PWD)/dot_vim/bundle/ultisnips; \
	fi

build-ctrlp:
	if [ ! -d $(PWD)/dot_vim/bundle/ctrlp.vim ]; \
	then \
		git clone https://github.com/kien/ctrlp.vim \
			$(PWD)/dot_vim/bundle/ctrlp.vim; \
 	fi

build-airline-themes:
	if [ ! -d $(PWD)/dot_vim/bundle/ctrlp.vim ]; \
	then \
		git clone https://github.com/vim-airline/vim-airline-themes \
			$(PWD)/dot_vim/bundle/vim-airline-themes; \
 	fi

#------------------------------------------------------------------------------
# update
#------------------------------------------------------------------------------
update:
	@echo -n "Update 'vim' configuration..."
	@rm -rf dot_vim/*
	@cp -r $(HOME)/.vim/* dot_vim/
	@cp $(HOME)/.vimrc dot_vimrc
	@echo ": done"

#------------------------------------------------------------------------------
# uninstall
#------------------------------------------------------------------------------
uninstall:
	@echo -n "Uninstall 'vim' configuration..."
	@rm -f $(HOME)/.vimrc
	@rm -rf $(HOME)/.vim
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('VIM')"
	@echo ": done"

#------------------------------------------------------------------------------
# install
#------------------------------------------------------------------------------
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
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.create()"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('VIM')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_create('VIM')"
	@echo ": done"

#------------------------------------------------------------------------------
# cleans
#------------------------------------------------------------------------------
clean:
	@echo -n "Clean 'vim' built in plugins..."
	@rm -rf dot_vim/bundle/*
	@rm -rf dot_vim/spell/*
	@echo ": done"

clean-backups:
	@echo -n "Clean 'vim' backup configurations..."
	@find $(HOME)/.* -maxdepth 1 -type d -name ".vim_*_*_*_*_*_*" | xargs rm -rf
	@find $(HOME)/.* -maxdepth 1 -type f -name ".vimrc_*_*_*_*_*_*" | xargs rm -f
	@echo ": done"

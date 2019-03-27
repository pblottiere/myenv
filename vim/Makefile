install:
	@echo -n "Install 'vim' configuration..."
	@ln -sf $(PWD)/dot_vim $(HOME)/.vim
	@ln -sf $(PWD)/dot_vimrc $(HOME)/.vimrc
	@echo ": done"

all: build-ycm build-autoclose build-indentline build-tagbar build-spell \
	 build-nerdtree build-syntastic build-snippets build-ultisnips \
	 build-airline build-ctrlp build-airline-themes build-gnupg \
	 build-sleuth build-gitgutter build-conquegdb build-nerdtree-git \
	 build-fugitive

build-fugitive:
	if [ ! -d $(PWD)/dot_vim/bundle/tpope/vim-fugitive ]; \
	then \
		git clone https://github.com/tpope/vim-fugitive \
			$(PWD)/dot_vim/bundle/vim-fugitive; \
	fi

build-conquegdb:
	if [ ! -d $(PWD)/dot_vim/bundle/Conque-GDB ]; \
	then \
		git clone https://github.com/vim-scripts/Conque-GDB \
			$(PWD)/dot_vim/bundle/Conque-GDB; \
	fi

build-nerdtree-git:
	if [ ! -d $(PWD)/dot_vim/bundle/nerdtree-git-plugin ]; \
	then \
		git clone https://github.com/Xuyuanp/nerdtree-git-plugin \
			$(PWD)/dot_vim/bundle/nerdtree-git-plugin; \
	fi

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

build-sleuth:
	if [ ! -d $(PWD)/dot_vim/bundle/vim-sleuth ]; \
	then \
		git clone https://github.com/tpope/vim-sleuth \
			$(PWD)/dot_vim/bundle/vim-sleuth; \
 	fi

build-gitgutter:
	if [ ! -d $(PWD)/dot_vim/bundle/vim-gitgutter ]; \
	then \
		git clone https://github.com/airblade/vim-gitgutter \
			$(PWD)/dot_vim/bundle/vim-gitgutter; \
 	fi

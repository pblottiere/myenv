# MyEnv

First of all:

````
$ sudo apt-get install git
$ git clone https://github.com/pblottiere/myenv
````

To install everything:

````
$ sudo apt-get install make
$ make install
````

## VIM

Plugins:
- ycm: Code completion engine
- autoclose: Auto-close chars feature
- indentline: Display vertical lines at each indentation level
- tagbar: Display tags of the current file ordered by scope
- spell: Spell chacking
- nerdtree: Tree explorer
- syntastic: Syntax checking
- snippets: Default snippets
- ultisnips: More snippets
- ctrlp: Fuzzy file finder
- airline: Status bar
- airline-themes: Airline themes
- gnupg: Editing of gpg encrypted files
- sleuth: Automatically adjusts 'shiftwidth' and 'expandtab' heuristically based on the current file
- gitgutter: Shows which lines have been added, modified, or removed (sign columns)
- conquegdb: GDB interface
- nerdtree-git: Show git status in nerdtree
- fugitive: Git wrapper to use git from vim

To compile plugins and install `~/.vimrc` and `~/.vim` directory:

````
$ sudo apt-get install exuberant-ctags cmake g++ python-dev
$ cd vim
$ make
$ make install
````

## Window Manager

To compile dwm and install `~/.conkyrc` and `~/.xinitrc`:

````
$ cd wm
$ make
$ make install
````

## Terminal

TODO

## VCS

### Git

To install `~/.gitconfig`, `~/.gitcolor`, `~/.gitcompletion` and
`~/.gitignore_global`:

````
$ sudo apt-get instal git
$ cd git
$ make install
````

## Tools

vmail / gcalcli

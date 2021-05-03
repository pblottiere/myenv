# MyEnv

First of all:

````
$ sudo apt-get install git
$ git clone https://github.com/pblottiere/myenv
````

To install everything:

````
$ sudo pacman -S make
$ make install
````

## Git

To install `~/.gitconfig`, `~/.gitcolor`, `~/.gitcompletion` and
`~/.gitignore_global`:

````
$ sudo pacman -S git
$ cd git
$ make install
````

Then edit your `~/.bashrc` with:

```` bash
source ~/.gitcompletion
source ~/.git-prompt.sh
source ~/.gitcolor

GIT_PS1_SHOWCOLORHINTS=1
GIT_PS1_SHOWDIRTYSTATE=1
GIT_PS1_SHOWUNTRACKEDFILES=1

PROMPT_COMMAND='__git_ps1 "" "\[\033[38;5;074m\]\W>\[\033[0m\] "'
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
$ sudo pacman -S TODO
$ cd vim
$ make
$ make install
````

## WM

To compile and install the window manager environment (`i3`, `polybar`, ...):

```` bash
$ sudo pacman -S awesome-terminal-fonts
$ cd wm
$ make
$ make install
````

## Terminal

To edit EET file:

```` bash
$ EDITOR=vim vieet base.cfg config
````

## Tools

To install various tools like:

- `bashtop`


```` bash
TODO
````

# MyEnv

First of all:

````
$ sudo pacman -S git
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
$ sudo pacman -S vim ctags
$ cd vim
$ make
$ make install
````

## WM

To compile and install the window manager environment (`i3`, `polybar`, ...):

```` bash
$ sudo pacman -S i3 polybar dmenu awesome-terminal-fonts binutils fakeroot gcc pkg-config
$ cd wm
$ make
$ make install
````

## Terminal

To edit EET file:

```` bash
$ EDITOR=vim vieet base.cfg config
````

Note: i3 config needs to call `terminology` with the proper `Tergeist` colorsheme

## Tools

To install various tools (`bashtop`, `pass clip` extension, ...) and custom
scripts:

```` bash
$ sudo pacman -S htop bat fzf xclip
$ cd tools
$ make install
````

Then add some alias:

```` bash
alias top='htop'
alias ping='$HOME/.cargo/bin/gping'
alias cat='$HOME/.local/bin/cat'
alias pass='pass clip'
alias space='sudo du -a -h | sort -h'
alias temp="watch -n 2 'sensors | grep Core'"
alias pass-gitlab='/usr/bin/pass work/hytech/gitlab | xclip -selection clipboard'
alias pass-gitlab-token='/usr/bin/pass work/hytech/pblottiere@access-token-gitlab | xclip -selection clipboard'
alias cmake-qgis='cmake -G Ninja -DWITH_SERVER=TRUE -DWITH_3D=FALSE -DWITH_QTWEBKIT=FALSE -DCMAKE_BUILD_TYPE=Debug ..'
alias wm='sudo wifi-menu'

````

## Passphrase mode

Configure `pinentry`:

```` bash
$ cat /etc/pinentry/preexec
#!/hint/sh
exec /usr/bin/pinentry-tty "$@"
````

## Keyboard

```` console
$ cd kb
$ make install
$ make compile
````

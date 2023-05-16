#! /bin/sh

if [[ $(file $1) == *" image data"* ]]; then
  tycat $1
else
  BAT_THEME=gruvbox-light bat --paging=never $@
fi

#! /bin/sh

if [[ $(file $1) == *" image data"* ]]; then
  tycat $1
else
  bat $1
fi

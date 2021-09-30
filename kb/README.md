# mykb

Install QMK firmware:

```` bash
$ cd mykb
$ qmk setup -H $(pwd)/qmk_firmware
````

Compile custom keymap:

```` bash
$ make compile
````

Flash:

```` bash
$ qmk flash -kb boardsource/4x12 -km pblottiere -bl dfu
````

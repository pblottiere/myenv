install:
	qmk setup -H $(PWD)/qmk_firmware -y

flash:
	qmk flash -kb boardsource/4x12 -km pblottiere -bl dfu

compile:
	mkdir -p qmk_firmware/keyboards/boardsource/4x12/keymaps/pblottiere
	cp keymap.c qmk_firmware/keyboards/boardsource/4x12/keymaps/pblottiere/
	qmk compile -kb boardsource/4x12 -km pblottiere

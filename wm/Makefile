PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

all:
	@rm -rf dwm
	@git clone https://github.com/pblottiere/dwm
	@cd dwm && make

install:
	@echo -n "Install 'wm' configuration..."
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('WM')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_create('WM')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_add('WM', 'export MYENV_WMPATH=$(PWD)')"
	@ln -sf $(PWD)/dot_conkyrc $(HOME)/.conkyrc
	@ln -sf $(PWD)/dot_xinitrc $(HOME)/.xinitrc
	@echo ": done"

PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

install:
	@echo -n "Install 'git' configuration..."
	@ln -sf $(PWD)/dot_gitconfig $(HOME)/.gitconfig
	@ln -sf $(PWD)/dot_gitcolor $(HOME)/.gitcolor
	@ln -sf $(PWD)/dot_gitcompletion $(HOME)/.gitcompletion
	@ln -sf $(PWD)/dot_gitignore_global $(HOME)/.gitignore_global
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.create()"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('GIT')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_add('GIT', 'source ~/.gitcolor')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_add('GIT', 'source ~/.gitcompletion')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_create('GIT')"
	@echo ": done"

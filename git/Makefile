PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

install:
	@echo -n "Install 'git' configuration..."
	@ln -sf $(PWD)/dot_gitconfig $(HOME)/.gitconfig
	@ln -sf $(PWD)/dot_gitcolor $(HOME)/.gitcolor
	@ln -sf $(PWD)/dot_gitcompletion $(HOME)/.gitcompletion
	@ln -sf $(PWD)/dot_gitignore_global $(HOME)/.gitignore_global
	@ln -sf $(PWD)/dot_git_prompt $(HOME)/.git-prompt.sh
	@echo ": done"

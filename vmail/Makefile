#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#-------------------------------------------------------------------------------
# update
#-------------------------------------------------------------------------------
update:
	@echo -n "Update 'vmail' configuration..."
	@cp $(HOME)/.vmail/default/.vmailrc dot_vmailrc
	@echo ": done"

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall:
	@echo -n "Uninstall 'vmail' configuration..."
	@rm -f $(HOME)/.vmail/default/.vmailrc
	@echo ": done"

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install:
	@echo -n "Install 'vmail' configuration..."
	@if [ -f $(HOME)/.vmail/default/.vmailrc ]; \
	then \
		mv $(HOME)/.vmail/default/.vmailrc $(HOME)/.vmail/default/.vmailrc_$(NOW); \
	fi
	@cp dot_vmailrc $(HOME)/.vmail/default/.vmailrc
	@echo ": done"

#-------------------------------------------------------------------------------
# clean
#-------------------------------------------------------------------------------
clean:
	@echo -n "Clean 'vmail' configuration..."
	@find $(HOME)/.vmail/default/* -maxdepth 1 -type f -name ".vmailrc_*_*_*_*_*_*" | xargs rm -f
	@echo ": done"

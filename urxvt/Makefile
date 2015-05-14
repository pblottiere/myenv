#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#-------------------------------------------------------------------------------
# update
#-------------------------------------------------------------------------------
update:
	@echo -n "Update 'urxvt' configuration..."
	@cp $(HOME)/.Xdefaults dot_xdefaults
	@echo ": done"

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall:
	@echo -n "Uninstall 'urxvt' configuration..."
	@rm -f $(HOME)/.Xdefaults
	@echo ": done"

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install:
	@echo -n "Install 'urxvt' configuration..."
	@if [ -f $(HOME)/.Xdefaults ]; \
	then \
		mv $(HOME)/.Xdefaults $(HOME)/.Xdefaults_$(NOW); \
	fi
	@cp dot_xdefaults $(HOME)/.Xdefaults
	@echo ": done"

#-------------------------------------------------------------------------------
# clean
#-------------------------------------------------------------------------------
clean:
	@echo -n "Clean 'urxvt' configuration..."
	@find $(HOME)/.* -maxdepth 1 -type f -name ".Xdefaults_*_*_*_*_*_*" | xargs rm -f
	@echo ": done"

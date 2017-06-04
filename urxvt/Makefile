#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#-------------------------------------------------------------------------------
# all
#-------------------------------------------------------------------------------
all: install

#-------------------------------------------------------------------------------
# update
#-------------------------------------------------------------------------------
update:
	@echo -n "Update 'urxvt' configuration..."
	@cp $(HOME)/.Xdefaults dot_xdefaults
	@cp -r $(HOME)/.urxvt/* dot_urxvt/
	@echo ": done"

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall:
	@echo -n "Uninstall 'urxvt' configuration..."
	@rm -f $(HOME)/.Xdefaults
	@rm -rf $(HOME)/.urxvt
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
	@cp dot_xdefaults $(HOME)/.Xresources
	@if [ -f $(HOME)/.urxvt ]; \
	then \
		mv $(HOME)/.urxvt $(HOME)/.urxvt_$(NOW); \
	fi
	@xrdb $(HOME)/.Xdefaults
	@xrdb $(HOME)/.Xresources
	@cp -r dot_urxvt $(HOME)/.urxvt
	@echo ": done"

#-------------------------------------------------------------------------------
# clean
#-------------------------------------------------------------------------------
clean-backups:
	@echo -n "Clean 'urxvt' configuration..."
	@find $(HOME)/.* -maxdepth 1 -type f -name ".Xdefaults_*_*_*_*_*_*" | xargs rm -f
	@find $(HOME)/.* -maxdepth 1 -type d -name ".urxvt_*_*_*_*_*_*" | xargs rm -f
	@echo ": done"

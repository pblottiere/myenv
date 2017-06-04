#------------------------------------------------------------------------------
# const, paths
#------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
VERSION=$(shell awesome --version | head -1 | cut -d ' ' -f 2)

#------------------------------------------------------------------------------
# all
#------------------------------------------------------------------------------
all: build-obvious

#------------------------------------------------------------------------------
# build
#------------------------------------------------------------------------------
build-obvious:
	@if [ ! -d $(PWD)/obvious ]; \
	then \
		git clone https://github.com/hoelzro/obvious; \
	fi

#------------------------------------------------------------------------------
# update
#------------------------------------------------------------------------------
update:
	@echo -n "Update 'awesome' configuration..."
	@cp $(HOME)/.config/awesome/rc.lua rc.lua
	@echo ": done"

#------------------------------------------------------------------------------
# install
#------------------------------------------------------------------------------
install:
	@echo -n "Install 'awesome' configuration..."
	@if [ -d $(HOME)/.config/awesome ]; \
	then \
		mv $(HOME)/.config/awesome $(HOME)/.config/awesome_$(NOW); \
	fi
	@mkdir $(HOME)/.config/awesome
	@cp rc-$(VERSION).lua $(HOME)/.config/awesome/rc.lua
	@cp -r obvious $(HOME)/.config/awesome/
	@echo ": done"

#------------------------------------------------------------------------------
# cleans
#------------------------------------------------------------------------------
clean-backups:
	@echo -n "Clean 'awesome' backup configurations..."
	@find $(HOME)/.config/* -maxdepth 1 -type d -name "awesome_*_*_*_*_*_*" | xargs rm -rf
	@echo ": done"

clean:
	rm -rf obvious

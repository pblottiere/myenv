#-------------------------------------------------------------------------------
# const, paths
#-------------------------------------------------------------------------------
NOW=$(shell date +"%m_%d_%y_%H_%M_%S")
PYDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/../scripts

#-------------------------------------------------------------------------------
# update
#-------------------------------------------------------------------------------
update:
	@echo -n "Update 'svn' configuration..."
	@cp $(HOME)/.svn/svn-colors.py svn-colors.py
	@echo ": done"

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall:
	@echo -n "Uninstall 'svn' configuration..."
	@rm -f $(HOME)/.svn/svn-colors.py
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('SVN')"
	@echo ": done"

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install:
	@echo -n "Install 'svn' configuration..."
	@if [ -d $(HOME)/.svn ]; \
	then \
		mv $(HOME)/.svn $(HOME)/.svn_$(NOW); \
	fi
	@mkdir -p $(HOME)/.svn
	@cp svn-colors.py $(HOME)/.svn
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_delete('SVN')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_create('SVN')"
	@PYTHONPATH=$(PYDIR) python -c "import myenvrc; myenvrc.part_add('SVN', 'alias svn=\'python $(HOME)/.svn/svn-colors.py\'')"
	@. $(HOME)/.bashrc
	@chmod a+x $(HOME)/.svn/svn-colors.py
	@echo ": done"

#-------------------------------------------------------------------------------
# clean
#-------------------------------------------------------------------------------
clean:
	@echo -n "Clean 'svn' configuration..."
	@find $(HOME)/.* -maxdepth 1 -type d -name ".svn_*_*_*_*_*_*" | xargs rm -rf
	@echo ": done"

#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall-apps:
	@echo -n "Uninstall 'fluxbox/apps' configuration..."
	@python -c "import apps; apps.part_delete()"
	@echo ": done"

uninstall-keys:
	@echo -n "Uninstall 'fluxbox/keys' configuration..."
	@python -c "import keys; keys.part_delete()"
	@echo ": done"

uninstall: uninstall-apps uninstall-keys

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install-apps:
	@echo -n "Install 'fluxbox/apps' configuration..."
	@python -c "import apps; apps.part_delete()"
	@python -c "import apps; apps.part_create()"
	@python -c "import apps; apps.part_add('[app] (name=urxvt)')"
	@python -c "import apps; apps.part_add('    [Deco]    {NONE}')"
	@python -c "import apps; apps.part_add('[end]')"
	@echo ": done"

install-keys:
	@echo -n "Install 'fluxbox/keys' configuration..."
	@python -c "import keys; keys.part_delete()"
	@python -c "import keys; keys.part_create()"
	@python -c "import keys; keys.part_add('Mod4 w Mod4 q :ArrangeWindowsVertical')"
	@python -c "import keys; keys.part_add('Mod4 w Mod4 a :ArrangeWindowsHorizontal')"
	@echo ": done"

install: install-apps install-keys

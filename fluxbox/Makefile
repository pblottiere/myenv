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

uninstall-startup:
	@echo -n "Uninstall 'fluxbox/startup' configuration..."
	@python -c "import startup; startup.part_delete()"
	@echo ": done"

uninstall: uninstall-apps uninstall-keys uninstall-startup
	@echo "You should reload your fluxbox configuration..."

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install-apps:
	@echo -n "Install 'fluxbox/apps' configuration..."
	@python -c "import apps; apps.part_delete()"
	@python -c "import apps; apps.part_create()"
	@python -c "import apps; apps.part_add('[end]')"
	@python -c "import apps; apps.part_add('    [Deco]    {NONE}')"
	@python -c "import apps; apps.part_add('[app] (name=urxvt)')"
	@echo ": done"

install-keys:
	@echo -n "Install 'fluxbox/keys' configuration..."
	@python -c "import keys; keys.part_delete()"
	@python -c "import keys; keys.part_create()"
	@python -c "import keys; keys.part_add('Mod1 F1 :Exec urxvt')"
	@python -c "import keys; keys.part_add('Mod4 w Mod4 q :ArrangeWindowsVertical')"
	@python -c "import keys; keys.part_add('Mod4 w Mod4 a :ArrangeWindowsHorizontal')"
	@echo ": done"

install-startup:
	@echo -n "Install 'fluxbox/startup' configuration"
	@python -c "import startup; startup.part_delete()"
	@python -c "import startup; startup.part_create()"
	@python -c "import startup; startup.part_add('xcompmgr &')"
	@echo ": done"

install: install-apps install-keys install-startup
	@echo "You should reload your fluxbox configuration..."

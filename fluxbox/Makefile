#-------------------------------------------------------------------------------
# uninstall
#-------------------------------------------------------------------------------
uninstall-apps:
	@python -c "import apps; apps.part_delete()"

uninstall-keys:
	@python -c "import keys; keys.part_delete()"

uninstall: uninstall-apps uninstall-keys

#-------------------------------------------------------------------------------
# install
#-------------------------------------------------------------------------------
install-apps:
	@python -c "import apps; apps.part_delete()"
	@python -c "import apps; apps.part_create()"
	@python -c "import apps; apps.part_add('[app] (name=urxvt)')"
	@python -c "import apps; apps.part_add('    [Deco]    {NONE}')"
	@python -c "import apps; apps.part_add('[end]')"

install-keys:
	@python -c "import keys; keys.part_delete()"
	@python -c "import keys; keys.part_create()"
	@python -c "import keys; keys.part_add('Mod4 w Mod4 q :ArrangeWindowsVertical')"
	@python -c "import keys; keys.part_add('Mod4 w Mod4 a :ArrangeWindowsHorizontal')"

install: install-apps install-keys

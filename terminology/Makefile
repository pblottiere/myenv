.PHONY: dark light

update:
	@eet -r colorschemes.eet dark
	@eet -e colorschemes.eet Dark dark 1
	@eet -r colorschemes.eet light
	@eet -e colorschemes.eet Light light 1

install:
	@echo -n "Install 'terminology' configuration..."
	@ln -sf $(PWD)/colorschemes.eet $(HOME)/.config/terminology/colorschemes.eet
	@ln -sf $(PWD)/config $(HOME)/.config/terminology/
	@ln -sf $(PWD)/config/dark/base.cfg $(HOME)/.config/terminology/
	@echo ": done"

dark:
	@echo -n "Install 'terminology' dark configuration..."
	@ln -sf $(PWD)/config/dark/base.cfg $(HOME)/.config/terminology/config/standard/
	@echo ": done"

light:
	@echo -n "Install 'terminology' light configuration..."
	@ln -sf $(PWD)/config/light/base.cfg $(HOME)/.config/terminology/config/standard/
	@echo ": done"

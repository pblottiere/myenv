update:
	@eet -r colorschemes.eet dark
	@eet -e colorschemes.eet Dark dark 1
	@eet -r colorschemes.eet light
	@eet -e colorschemes.eet Light light 1

install:
	@echo -n "Install 'terminology' configuration..."
	@ln -sf $(PWD)/colorschemes.eet $(HOME)/.config/terminology/colorschemes.eet
	@echo ": done"

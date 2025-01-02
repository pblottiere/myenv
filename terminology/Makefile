.PHONY: install

install:
	@echo -n "Install 'terminology' configuration..."
	@mkdir -p $(HOME)/.config/terminology/colorschemes/
	@ln -sf $(PWD)/Tergeist.eet $(HOME)/.config/terminology/colorschemes/
	@mkdir -p $(HOME)/.config/terminology/config/standard
	@ln -sf $(PWD)/base.cfg $(HOME)/.config/terminology/config/standard/base.cfg
	@echo ": done"

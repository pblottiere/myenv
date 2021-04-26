all:
	@git clone https://aur.archlinux.org/polybar.git
	@cd polybar && makepkg -si

install:
	@echo -n "Install 'wm' configuration..."
	@ln -sf $(PWD)/dot_xinitrc $(HOME)/.xinitrc
	@ln -sf $(PWD)/i3.config $(HOME)/.config/i3/config
	@mkdir -p $(HOME)/.config/polybar
	@ln -sf $(PWD)/polybar.config $(HOME)/.config/polybar/config
	@ln -sf $(PWD)/launch.sh $(HOME)/.config/polybar/launch.sh
	@echo ": done"

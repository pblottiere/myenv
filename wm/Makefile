all:
	@git clone https://aur.archlinux.org/polybar.git
	@cd polybar && makepkg -si

install:
	@echo -n "Install 'wm' configuration..."
	@ln -sf $(PWD)/dot_xinitrc $(HOME)/.xinitrc
	@ln -sf $(PWD)/i3.config $(HOME)/.config/i3/config
	@mkdir -p $(HOME)/.config/polybar
	@ln -sf $(PWD)/polybar.ini $(HOME)/.config/polybar/polybar.ini
	@ln -sf $(PWD)/launch.sh $(HOME)/.config/polybar/launch.sh
	@mkdir -p $(HOME)/.local/share/fonts/
	@ln -sf $(PWD)/fonts/iosevka_nerd_font.ttf $(HOME)/.local/share/fonts/iosevka_nerd_font.ttf
	@ln -sf $(PWD)/fonts/noto_sans.ttf $(HOME)/.local/share/fonts/noto_sans.ttf
	@echo ": done"

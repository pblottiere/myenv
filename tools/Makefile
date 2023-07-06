.PHONY: pass-clip

install: pass-clip dark
	@echo -n "Install 'tools' configuration..."
	@mkdir -p $(HOME)/.local/bin
	@ln -sf $(PWD)/w2d.py $(HOME)/.local/bin/w2d
	@echo ": done"

pass-clip:
	rm -rf pass-clip
	git clone https://aur.archlinux.org/pass-clip.git
	cd pass-clip && makepkg -si

dark:
	@mkdir -p $(HOME)/.local/bin
	@ln -sf $(PWD)/cat-dark.sh $(HOME)/.local/bin/cat

light:
	@mkdir -p $(HOME)/.local/bin
	@ln -sf $(PWD)/cat-light.sh $(HOME)/.local/bin/cat

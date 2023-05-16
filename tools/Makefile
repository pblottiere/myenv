.PHONY: pass-clip

install: pass-clip
	@echo -n "Install 'tools' configuration..."
	@mkdir -p $(HOME)/.local/bin
	@ln -sf $(PWD)/cat.sh $(HOME)/.local/bin/cat
	@ln -sf $(PWD)/w2d.py $(HOME)/.local/bin/w2d
	@echo ": done"

pass-clip:
	rm -rf pass-clip
	git clone https://aur.archlinux.org/pass-clip.git
	cd pass-clip && makepkg -Si

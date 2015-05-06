now=$(shell date +"%m_%d_%y_%H_%M_%S")

update:
	cp $(HOME)/.gitconfig dot_gitconfig

install:
	@if [ -f $(HOME)/.gitconfig ]; \
	then \
		mv $(HOME)/.gitconfig $(HOME)/.gitconfig_$(now); \
	fi
	cp dot_gitconfig $(HOME)/.gitconfig

clean:
	find $(HOME)/.* -maxdepth 1 -type f -name ".gitconfig_*_*_*_*_*_*" | xargs rm -f

now=$(shell date +"%m_%d_%y_%H_%M_%S")

update:
	cp -r $(HOME)/.vim/* dot_vim/
	cp $(HOME)/.vimrc dot_vimrc

install:
	@if [ -d $(HOME)/.vim ]; \
	then \
		mv $(HOME)/.vim $(HOME)/.vim_$(now); \
	fi
	cp -r dot_vim $(HOME)/.vim

	@if [ -f $(HOME)/.vimrc ]; \
	then \
		mv $(HOME)/.vimrc $(HOME)/.vimrc_$(now); \
	fi
	cp dot_vimrc $(HOME)/.vimrc

clean:
	find $(HOME)/.* -maxdepth 1 -type d -name ".vim_*_*_*_*_*_*" | xargs rm -rf
	find $(HOME)/.* -maxdepth 1 -type f -name ".vimrc_*_*_*_*_*_*" | xargs rm -f

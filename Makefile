#------------------------------------------------------------------------------
# update
#------------------------------------------------------------------------------
update-vim:
	cd vim && make update

update-git:
	cd git && make update

update: update-vim update-git

#------------------------------------------------------------------------------
# install
#------------------------------------------------------------------------------
install-vim:
	cd vim && make install

install-git:
	cd git && make install

install: install-vim install-git

#------------------------------------------------------------------------------
# clean
#------------------------------------------------------------------------------
clean-vim:
	cd vim && make clean

clean-git:
	cd git && make clean

clean: clean-vim clean-git

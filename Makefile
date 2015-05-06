MYENVRC=.myenvrc

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
install-myenvrc:
	if [ "`cat ~/.bashrc | grep $(MYENVRC) | wc -l`" = "0" ]; \
	then \
		echo "\nsource ~/$(MYENVRC)" >> ~/.bashrc; \
		touch ~/$(MYENVRC); \
	fi

install-vim:
	cd vim && make install

install-git:
	cd git && make install

install: install-myenvrc install-vim install-git

#------------------------------------------------------------------------------
# uninstall
#------------------------------------------------------------------------------
uninstall-myenvrc:
	rm ~/$(MYENVRC)

uninstall: uninstall-myenvrc

#------------------------------------------------------------------------------
# clean
#------------------------------------------------------------------------------
clean-vim:
	cd vim && make clean

clean-git:
	cd git && make clean

clean: clean-vim clean-git

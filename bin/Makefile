all: build-ycm-generator bulid-gcalcli

build-gcalcli:
	if [ ! -d $(PWD)/gcalcli ]; \
        then \
	       git clone https://github.com/insanum/gcalcli \
		$(PWD)/gcalcli; \
	fi

build-ycm-generator:
	if [ ! -d $(PWD)/YCM-Generator ]; \
        then \
	       git clone https://github.com/rdnetto/YCM-Generator \
		$(PWD)/YCM-Generator; \
	fi

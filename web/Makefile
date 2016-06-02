RES_FOLDER	= 'res'
TARGET_FILE	= 'file-list.txt'

.PHONY: docs install clean

docs:
	$(RES_FOLDER)/create_docs.sh $(RES_FOLDER)/$(TARGET_FILE)

install:
ifeq ($(INSTALL_PATH),)
	@echo "Set INSTALL_PATH the location where you publish"
	@echo "For example, export INSTALL_PATH=http://where.html.files.go"
else
	@echo "Connect to the server to upload files"
	ALL_HTMLS := $(call rwildcard,foo/,*.html)
subdirs=$(wildcard */)
sources=$(wildcard $(addsuffix *.html,$(subdirs)))
objects=$(patsubst %.html,%.html,$(sources))
	@echo $(objects)
	@echo "hi"
endif

clean:
	rm -rf waggle_web
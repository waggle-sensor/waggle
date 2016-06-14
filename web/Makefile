RES_FOLDER	= 'res'
TARGET_FILE	= 'file-list.txt'
CHECK_DIR = waggle_web

.PHONY: help docs install clean

help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo "  docs       to make html files from the markdown files"
	@echo "  install    to upload generated html files to remote server"
	@echo "  clean      to clear all generated html files"

docs:
	$(RES_FOLDER)/create_docs.sh $(RES_FOLDER)/$(TARGET_FILE)

install:
ifeq ($(INSTALL_URL),)
	@echo "Set INSTALL_URL the location where you publish"
	@echo "For example, export INSTALL_URL=ID@http://your.website.domain:where/html/files/go"
else
	
ifeq ($(wildcard $(CHECK_DIR)/.*),)
	@echo "The folder does not exist!"
	@echo "run 'make docs' first!"
else
	@echo "Connect to the server to upload files"
	$(shell scp -r $(CHECK_DIR) $(INSTALL_URL))
endif
endif

clean:
	rm -rf waggle_web
RES_FOLDER	= 'res'
TARGET_FILE	= 'file-list.txt'

.PHONY: docs clean

docs:
	$(RES_FOLDER)/create_docs.sh $(RES_FOLDER)/$(TARGET_FILE)

clean:
	find . -name "*.html" -type f -delete

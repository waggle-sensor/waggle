# The commands in this file may need updated.

.PHONY: uninstall install

clean:
	rm -rf waggle.egg-info dist build
	rm -rf `find -name "*.pyc"`

dist:

develop:

install: setup.py
	python setup.py install --record ${INSTALLED_FILES_LIST}

uninstall:
	rm -r ${INSTALL_PREFIX}*


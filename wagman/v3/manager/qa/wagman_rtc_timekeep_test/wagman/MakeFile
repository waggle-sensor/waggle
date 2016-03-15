CC = $(ARD_HOME)/arduino
BUILD_DIR = ./build
BIN_DIR = ./bin
CFLAGS  = --verbose-build --verify

all: clean	$(TARGET)

$(TARGET): $(TARGET).ino
	$(CC) --board $(BOARD_FLASH) $(CFLAGS) --pref build.path=$(BUILD_DIR) $(TARGET).ino
	$(BUILD_COMPLETE)

clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(BUILD_DIR)/*
	rm -f *~


install:	clean	all
	$(PRE_FLASH_COMMAND)
	$(FLASH_BOARD)

program:
	$(PRE_FLASH_COMMAND)
	$(FLASH_BOARD)


run:    install
	sleep 2
	screen $(LINKPORT) $(SERIALBAUD)

initialize:
	./timeset.sh
	make install
	sleep 2
	echo "" > rtc_conf.cpp
	make run

connect:
	screen $(LINKPORT) $(SERIALBAUD)


## Does not seem to work for some reason :(.
# new:
#   $(BOOT_LOADER)
#   sleep 6
#   make initialize


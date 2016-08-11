ARD_HOME = $(ARDUINO_DIR)
TARGET = integrated
PACKAGE = arduino
ARCH = sam
BOARD = arduino_due_x
TYPE =
FLASHER_BAUD_RATE = 115200
#PORT = ttyACM0
PORT = waggle_coresense
BOARD_FLASH = $(PACKAGE):$(ARCH):$(BOARD)
BOOT_LOADER_TYPE = wiring
PRE_FLASH_COMMAND = stty -F /dev/$(PORT) 1200 hupcl; sleep 2
#FLASHER = $(ARD_HOME)/Atmel_SAM/packages/arduino/tools/bossac/1.6.1-arduino/bossac
FLASHER = ./bossac
FLASH_BOARD = $(FLASHER) -i -d --port=$(PORT) -U true -e -w -v -b $(BIN_DIR)/$(TARGET).ino.bin -R
BUILD_COMPLETE = mv $(BUILD_DIR)/$(TARGET).ino.bin $(BIN_DIR)/
LINKPORT = /dev/$(PORT)
SERIALBAUD = 115200
CC = $(ARD_HOME)/arduino
BUILD_DIR = ./build
BIN_DIR = ./bin
CFLAGS  = --verbose-build --verify

all: clean	$(TARGET)

$(TARGET): $(TARGET).ino
	$(CC) --board $(BOARD_FLASH) $(CFLAGS) --pref build.path=$(BUILD_DIR) $(TARGET).ino
	$(BUILD_COMPLETE)

clean:
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

connect:
	sleep 2
	screen $(LINKPORT) $(SERIALBAUD)

test:	program connect

do:	install
	sleep 2
	python coresense_plugin/coresense.py

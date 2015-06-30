ARD_HOME = /home/max/repos/waggle_version0.3_max/resources/compilers/arduino-1.6.5-linux/arduino_64
TARGET = i2c_rs232_forwarder
PACKAGE = arduino
ARCH = avr
BOARD = mega
TYPE = atmega2560
FLASHER_BAUD_RATE = 115200
PORT = /dev/ttyACM0
BOARD_FLASH = $(PACKAGE):$(ARCH):$(BOARD):cpu=$(TYPE)
BOOT_LOADER_TYPE = wiring
PRE_FLASH_COMMAND = #
CC = $(ARD_HOME)/arduino
BUILD_DIR = ./build
BIN_DIR = ./bin
CFLAGS  = --verbose-build --verify
FLASHER = $(ARD_HOME)/hardware/tools/avr/bin/avrdude
FLASHER_CONFIGS = $(ARD_HOME)/hardware/tools/avr/etc/avrdude.conf

all: $(TARGET)

$(TARGET): $(TARGET).ino
	$(CC) --board $(BOARD_FLASH) $(CFLAGS) --pref build.path=$(BUILD_DIR) $(TARGET).ino
	mv $(BUILD_DIR)/$(TARGET).cpp.hex $(BIN_DIR)
	rm -rf $(BUILD_DIR)/*
clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(BUILD_DIR)/*

install:
	$(PRE_FLASH_COMMAND)
	$(FLASHER) -C$(FLASHER_CONFIGS) -v -p$(TYPE) -c$(BOOT_LOADER_TYPE) -P$(PORT) -b$(FLASHER_BAUD_RATE) -D -Uflash:w:$(BIN_DIR)/$(TARGET).cpp.hex:i

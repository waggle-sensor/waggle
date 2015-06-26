ARD_HOME = /home/max/repos/waggle_version0.3_max/resources/compilers/arduino-1.6.5-linux/arduino_64
TARGET = envsenseCluster_v1.1
PACKAGE = arduino
ARCH = avr
BOARD = mega
TYPE = atmega2560
FLASHER_BAUD_RATE = 115200
PORT = /dev/ttyACM0
CC = $(ARD_HOME)/arduino
BUILD_DIR = ./build
BIN_DIR = ./bin
CFLAGS  = --verbose-build --verify
FLASHER = $(ARD_HOME)/hardware/tools/avr/bin/avrdude
FLASHER_CONFIGS = $(ARD_HOME)/hardware/tools/avr/etc/avrdude.conf

all: $(TARGET)

$(TARGET): $(TARGET).ino
	$(CC) --board $(PACKAGE):$(ARCH):$(BOARD):cpu=$(TYPE) $(CFLAGS) --pref build.path=$(BUILD_DIR) $(TARGET).ino
	mv $(BUILD_DIR)/$(TARGET).cpp.hex $(BIN_DIR)
	rm -rf $(BUILD_DIR)/*
clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(BUILD_DIR)/*

install:
	$(FLASHER) -C$(FLASHER_CONFIGS) -v -p$(TYPE) -cwiring -P$(PORT) -b$(FLASHER_BAUD_RATE) -D -Uflash:w:$(BIN_DIR)/$(TARGET).cpp.hex:i

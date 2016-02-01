ARD_HOME = /home/rajesh/Desktop/arduino-1.6.6
TARGET = nc_power_on
PACKAGE = arduino
ARCH = avr
BOARD = micro
TYPE = m32u4
FLASHER_BAUD_RATE = 57600
PORT = /dev/ttyACM0
BOARD_FLASH = $(PACKAGE):$(ARCH):$(BOARD)
BOOT_LOADER_TYPE = avr109
PRE_FLASH_COMMAND = stty -F $(PORT) 1200 hupcl; sleep 1
FLASHER = $(ARD_HOME)/hardware/tools/avr/bin/avrdude
FLASHER_CONFIGS = $(ARD_HOME)/hardware/tools/avr/etc/avrdude.conf
FLASH_BOARD = $(FLASHER) -C$(FLASHER_CONFIGS) -v -p$(TYPE) -c$(BOOT_LOADER_TYPE) -P$(PORT) -b$(FLASHER_BAUD_RATE) -D -Uflash:w:$(BIN_DIR)/$(TARGET).ino.hex:i
BUILD_COMPLETE = mv $(BUILD_DIR)/$(TARGET).ino.hex $(BIN_DIR)/
LINKPORT = $(PORT)
SERIALBAUD = 115200
CC = $(ARD_HOME)/arduino
BUILD_DIR = ./build
BIN_DIR = ./bin
CFLAGS  = --verbose-build --verify

all: $(TARGET)

$(TARGET): $(TARGET).ino
	$(CC) --board $(BOARD_FLASH) $(CFLAGS) --pref build.path=$(BUILD_DIR) $(TARGET).ino
	$(BUILD_COMPLETE)
	
clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(BUILD_DIR)/*
	rm -f *~

install: all
	$(PRE_FLASH_COMMAND)
	$(FLASH_BOARD)

run:    install
	sleep 2
	screen $(LINKPORT) $(SERIALBAUD)

connect:
	sleep 2
	screen $(LINKPORT) $(SERIALBAUD)

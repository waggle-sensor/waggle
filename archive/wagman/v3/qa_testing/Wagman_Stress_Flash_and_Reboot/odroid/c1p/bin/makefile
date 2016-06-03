TARGET = wagman
PACKAGE = arduino
ARCH = avr
BOARD = micro
TYPE = m32u4
FLASHER_BAUD_RATE = 57600
PORT = /dev/waggle_sysmon
BOARD_FLASH = $(PACKAGE):$(ARCH):$(BOARD)
BOOT_LOADER_TYPE = avr109
PRE_FLASH_COMMAND = stty -F $(PORT) 1200 hupcl; sleep 3
FLASHER = /usr/bin/avrdude
FLASHER_CONFIGS = ./avrdude.conf
FLASH_BOARD = $(FLASHER)  -l flash_avr.log -C$(FLASHER_CONFIGS) -v -p$(TYPE) -c$(BOOT_LOADER_TYPE) -P$(PORT) -b$(FLASHER_BAUD_RATE) -D -Uflash:w:$(BIN_DIR)/$(TARGET).ino.hex:i
BUILD_COMPLETE = mv $(BUILD_DIR)/$(TARGET).ino.hex $(BIN_DIR)/
LINKPORT = $(PORT)
SERIALBAUD = 115200
BOOT_LOADER = $(FLASHER) -C$(FLASHER_CONFIGS) -v -patmega32u4 -cstk500v2 -Pusb -Uflash:w:$(ARD_HOME)/hardware/arduino/avr/bootloaders/caterina/Caterina-Micro.hex:i -Ulock:w:0x2F:m
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

reset:
	$(PRE_FLASH_COMMAND)

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


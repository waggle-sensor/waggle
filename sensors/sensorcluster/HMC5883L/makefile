ARD_HOME = /digital/github/waggle/devtools/arduino/compilers/arduino-1.6.5-linux/arduino_64
TARGET = HMC5883L
PACKAGE = arduino
ARCH = sam
BOARD = arduino_due_x
TYPE = 
FLASHER_BAUD_RATE = 115200
PORT = ttyACM0
BOARD_FLASH = $(PACKAGE):$(ARCH):$(BOARD)
BOOT_LOADER_TYPE = wiring
PRE_FLASH_COMMAND = stty -F /dev/$(PORT) 1200 hupcl; sleep 2
FLASHER = $(ARD_HOME)/tools/bossac/1.3a-arduino/bossac
FLASH_BOARD = $(FLASHER) -i -d --port=$(PORT) -U true -e -w -v -b $(BIN_DIR)/$(TARGET).cpp.bin -R
BUILD_COMPLETE = mv $(BUILD_DIR)/$(TARGET).cpp.bin $(BIN_DIR)
LINKPORT = /dev/$(PORT)
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

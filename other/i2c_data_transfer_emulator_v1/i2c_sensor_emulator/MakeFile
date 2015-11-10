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

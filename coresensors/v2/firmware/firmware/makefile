FLASHER = ./bossac
PORT = ttyACM0
BIN_DIR = ./bin
TARGET=firmware
PRE_FLASH_COMMAND = stty -F /dev/$(PORT) 1200 hupcl; sleep 2
FLASH_BOARD = $(FLASHER) -i -d --port=$(PORT) -U true -e -w -v -b $(BIN_DIR)/$(TARGET).ino.bin -R

all:	program
program:
	$(PRE_FLASH_COMMAND)
	$(FLASH_BOARD)


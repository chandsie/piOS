TOOLCHAIN_BIN = /Users/chandsie/opt/cross/bin/
ARCH = arm-none-eabi
CPU = arm1176jzf-s

CC = $(TOOLCHAIN_BIN)$(ARCH)-gcc
AS = $(TOOLCHAIN_BIN)$(ARCH)-as
LD = $(TOOLCHAIN_BIN)$(ARCH)-ld
OC = $(TOOLCHAIN_BIN)$(ARCH)-objcopy
OD = $(TOOLCHAIN_BIN)$(ARCH)-objdump

CFLAGS = -mcpu=$(CPU) -std=c11 -fpic -ffreestanding -O2 -Wall -Wextra -pedantic
AFLAGS = -mcpu=$(CPU)
LFLAGS = --no-undefined

DBG_DIR = debug
OBJ_DIR = objects
SRC_DIR = ../source
HDR_DIR = ../include

KER_SRC_DIR = $(SRC_DIR)
KER_HDR_DIR = $(HDR_DIR)

KERSOURCES = $(wildcard $(KER_SRC_DIR)/*.c)
ASMSOURCES = $(wildcard $(KER_SRC_DIR)/*.s)
HEADERS = $(wildcard $(KER_HDR_DIR)/*.h)

OBJECTS = $(patsubst $(KER_SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(KERSOURCES))
OBJECTS += $(patsubst $(KER_SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(ASMSOURCES))

LINK = piOS.ld

TARGET = kernel.img
ELF = $(DBG_DIR)/kernel.elf
LIST = $(DBG_DIR)/kernel.list
MAP = $(DBG_DIR)/kernel.map

SD_CARD_DIR = /Volumes/boot
SD_CARD_DEV = /dev/disk2

build: $(TARGET) $(LIST)

$(TARGET): $(ELF)
	$(OC) $< -O binary $@

$(LIST): $(ELF) $(DBG_DIR)
	$(OD) -d $< > $@

$(ELF): $(OBJECTS) $(HEADERS) $(LINK) | $(DBG_DIR)
	$(LD) $(LFLAGS) -T $(LINK) -Map $(MAP) -o $@ $(OBJECTS)

$(OBJ_DIR)/%.o: $(KER_SRC_DIR)/%.s | $(OBJ_DIR)
	$(AS) $(AFLAGS) -I $(KER_SRC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(KER_SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(KER_SRC_DIR) -I $(KER_HDR_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

$(DBG_DIR):
	mkdir $@

.PHONY: clean install
install: $(TARGET) $(LIST)
	cp $< $(SD_CARD_DIR)
	diskutil eject $(SD_CARD_DEV)

clean:
	-rm -rf $(OBJ_DIR)
	-rm -rf $(DBG_DIR)
	-rm -f $(TARGET)

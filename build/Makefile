ARCH = arm-none-eabi
CPU = arm1176jzf-s

CC = $(ARCH)-gcc
AS = $(ARCH)-as
LD = $(ARCH)-ld

CCFLAGS = -mcpu=$(CPU) -pic -ffresstanding -O2 -Wall -Wextra
LDFLAGS = --no-undefined

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

LINK = kernel.ld

TARGET = kernel.img
ELF = kernel.elf
LIST = $(DBG_DIR)/kernel.list
MAP = $(DBG_DIR)/kernel.map

build: $(TARGET) $(LIST)

$(TARGET): $(ELF)
	$(ARCH)-objcopy $< -O binary $@

$(LIST): $(ELF) $(DBG_DIR)
	$(ARCH)-objdump -d $< > $@

$(ELF): $(OBJECTS) $(HEADERS) $(DBG_DIR)
	$(LD) $(LDFLAGS) -T $(LINK) -Map $(MAP) -o $@ 
 
$(OBJ_DIR)/%.o: $(KER_SRC_DIR)%.s $(OBJ_DIR)
	$(AS) $(CFLAGS) -I $(KER_SRC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(KER_SRC_DIR)%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(KER_SRC_DIR) -I $(KER_HDR_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

$(DBG_DIR):
	mkdir $@

.PHONY: clean
clean: 
	-rm -rf $(OBJ_DIR)
	-rm -rf $(DBG_DIR)
	-rm -f $(TARGET)

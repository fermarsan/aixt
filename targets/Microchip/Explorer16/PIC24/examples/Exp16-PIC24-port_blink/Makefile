# Compiler version
XCVERSION ?= 2.10

# Build directory
BUILD ?= build

# Target name
TARGET_NAME ?= main

# PIC microcontroller part number
PART ?= 24FJ128GA010

# Source files
SRC = main.c

# Toolchain configuration
ifeq ($(OS),Windows_NT)
    XC16_BASE = "C:\Program Files\Microchip\xc16\v"
    XC16 = $(XC16_BASE)$(XCVERSION)
    CC = $(XC16)\bin\xc16-gcc
    OBJCOPY = $(XC16)\bin\xc16-bin2hex
    TARGET_PATH = $(BUILD)\$(TARGET_NAME)
    MKDIR = mkdir
    RM = rmdir /s /q
else
    XC16_BASE = /opt/microchip/xc16/v
    XC16 = $(XC16_BASE)$(XCVERSION)
    CC = $(XC16)/bin/xc16-gcc
    OBJCOPY = $(XC16)/bin/xc16-bin2hex
    TARGET_PATH = $(BUILD)/$(TARGET_NAME)
    MKDIR = mkdir -p
    RM = rm -rf
endif

# Compiler and linker flags
CFLAGS = -mcpu=$(PART) -O1 -Wall -g
LDFLAGS = -Wl,--script=p$(PART).gld,--check-sections,--report-mem

# Get object files
OBJS = $(patsubst %.c,$(BUILD)/%.o,$(notdir $(SRC)))

# Default rule
all: $(BUILD)/$(TARGET_NAME).hex

# Rule to link object files into an ELF file
$(BUILD)/$(TARGET_NAME).elf: $(OBJS)
	@echo "Linking..."
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to convert ELF to HEX
$(BUILD)/$(TARGET_NAME).hex: $(BUILD)/$(TARGET_NAME).elf
	@echo "Generating HEX file..."
	$(OBJCOPY) $<

# Rule to compile C source files into object files
$(BUILD)/%.o: %.c | $(BUILD)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the build directory
$(BUILD):
	@$(MKDIR) $(BUILD)
	@echo "Created $(BUILD) folder"

# Clean rule
clean:
	@echo "Cleaning up..."
	-$(RM) $(BUILD)
	@echo "Deleted $(BUILD) folder"

.PHONY: all clean

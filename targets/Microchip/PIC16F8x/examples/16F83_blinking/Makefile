XCVERSION ?= 3.00

BUILD ?= build
TARGET_NAME ?= main

PART ?= PIC16F83

SRC = main.c

ifeq ($(OS),Windows_NT)
	XC8_BASE = "C:\Program Files\Microchip\xc8\v"
	XC8 = $(XC8_BASE)$(XCVERSION)
	CC = $(XC8)\bin\xc8-cc
	TARGET_PATH = $(BUILD)\$(TARGET_NAME)
	MKDIR = mkdir
else
	XC8_BASE = /opt/microchip/xc8/v
	XC8 = $(XC8_BASE)$(XCVERSION)
	CC = $(XC8)/bin/xc8-cc
	TARGET_PATH = $(BUILD)/$(TARGET_NAME)
	MKDIR = mkdir -p
endif


$(TARGET_NAME).hex: $(SRC)
ifneq "$(wildcard $(BUILD) )" ""
	@echo "$(BUILD) folder already exists"
else
	$(MKDIR) $(BUILD)
	@echo "Create $(BUILD) folder"
endif
	@echo "Create $@"
	$(CC) -mcpu=$(PART) -c -mdfp=$(XC8) -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=default  -msummary=-psect,-class,+mem,-hex,-file -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -o $(TARGET_PATH).p1 $(SRC)
	$(CC) -mcpu=$(PART) -Wl,-Map=$(TARGET_PATH).map -DXPRJ_default=default -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=$(XC8)  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -Wl,--memorysummary,$(TARGET_PATH).xml -o $(TARGET_PATH).elf  $(TARGET_PATH).p1

clean:
ifneq "$(wildcard $(BUILD) )" ""
	rm -fr $(BUILD)
	@echo "Delete $(BUILD) folder"
endif
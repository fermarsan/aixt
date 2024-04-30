XCVERSION ?= 2.46

BUILD ?= build
TARGET_NAME ?= main

ifeq ($(OS),Windows_NT)
XC8 = C:\Program\ Files\Microchip\xc8\v$(XCVERSION)
TARGET_PATH = $(BUILD)\$(TARGET_NAME)
CC = $(XC8)\bin\xc8-cc
else
XC8 = /opt/microchip/xc8/v$(XCVERSION)
TARGET_PATH = $(BUILD)/$(TARGET_NAME)
CC = $(XC8)/bin/xc8-cc
endif

PART ?= pic16f84a

SRC = \
	main.c \

$(TARGET_NAME).hex: $(SRC)
	mkdir -p $(BUILD)
	@echo "Create $@"
	$(CC) -mcpu=$(PART) -c -mdfp=$(XC8) -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=default  -msummary=-psect,-class,+mem,-hex,-file -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -o $(TARGET_PATH).p1 $(SRC)
	$(CC) -mcpu=$(PART) -Wl,-Map=$(TARGET_PATH).map -DXPRJ_default=default -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=$(XC8)  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -Wl,--memorysummary,$(TARGET_PATH).xml -o $(TARGET_PATH).elf  $(TARGET_PATH).p1

clean:
	rm -fr $(BUILD)
	@echo '$(BUILD) folder deleted'
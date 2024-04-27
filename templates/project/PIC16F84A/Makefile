XCVERSION = 2.46
XC8 = /opt/microchip/xc8/v$(XCVERSION)
CC = $(XC8)/bin/xc8-cc

TARGET_NAME = main
SRC = \
	main.c \

PART = pic16f84a

BUILD = build

$(TARGET_NAME).hex: $(SRC)
	mkdir -p $(BUILD)
	@echo "Create $@"
	$(CC) -mcpu=$(PART) -c -mdfp=$(XC8) -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=default  -msummary=-psect,-class,+mem,-hex,-file -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -o $(BUILD)/$(TARGET_NAME).p1 $(SRC)
	$(CC) -mcpu=$(PART) -Wl,-Map=$(BUILD)/$(TARGET_NAME).map -DXPRJ_default=default -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=$(XC8)  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -Wl,--memorysummary,$(BUILD)/$(TARGET_NAME).xml -o $(BUILD)/$(TARGET_NAME).elf  $(BUILD)/$(TARGET_NAME).p1

clean:
	rm -fr $(BUILD)
	@echo '$(BUILD) folder deleted'
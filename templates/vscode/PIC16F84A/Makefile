CC = /opt/microchip/xc8/v2.46/bin/xc8-cc
TARGET = main
SRC = main.c

DEVICE = pic16f84a
FAMILYPACK = /opt/microchip/mplabx/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8
BUILDPATH = build

$(TARGET).hex: $(SRC)
	mkdir $(BUILDPATH)
	$(CC) -mcpu=$(DEVICE) -c -mdfp=$(FAMILYPACK) -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=default  -msummary=-psect,-class,+mem,-hex,-file -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -o $(BUILDPATH)/$(TARGET).p1 $(SRC)
	$(CC) -mcpu=$(DEVICE) -Wl,-Map=$(BUILDPATH)/$(TARGET).map -DXPRJ_default=default -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=$(FAMILYPACK)  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -Wl,--memorysummary,$(BUILDPATH)/$(TARGET).xml -o $(BUILDPATH)/$(TARGET).elf  $(BUILDPATH)/$(TARGET).p1

clean:
	rm -r $(BUILDPATH)

CC = /opt/microchip/xc8/v2.46/bin/xc8-cc
CFLAGS = -Wall
TARGET = main
SRC = main.c

DEVICE = pic16f84a
BUILDPATH = build

$(TARGET).hex: $(SRC)
	$(CC) -mcpu=$(DEVICE) -c -mdfp=/opt/microchip/mplabx/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8 -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=default  -msummary=-psect,-class,+mem,-hex,-file -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -o $(BUILDPATH)/$(TARGET).p1 $(SRC)
	$(CC) -mcpu=$(DEVICE) -Wl,-Map=$(BUILDPATH)/$(TARGET).map -DXPRJ_default=default -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=/opt/microchip/mplabx/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -gdwarf-3 -mstack=compiled:auto:auto -Wl,--memorysummary,$(BUILDPATH)/$(TARGET).xml -o $(BUILDPATH)/$(TARGET).elf  $(BUILDPATH)/$(TARGET).p1

clean:
	rm -f $(TARGET)

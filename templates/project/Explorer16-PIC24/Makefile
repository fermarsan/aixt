XCVERSION ?= 2.10
XC16 ?= /opt/microchip/xc16/v$(XCVERSION)
CROSS_COMPILE = $(XC16)/bin/xc16-

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld

PART ?= 24FJ128GA010
PARTFAMILY = PIC24F

BUILD = build
TARGET_NAME = firmware

INC += -I.
INC += -I$(XC16)/include
INC += -I$(XC16)/support/$(PARTFAMILY)/h

CFLAGS_PIC16BIT = -mcpu=$(PART) -mlarge-code
CFLAGS += $(INC) -Wall -Werror -std=gnu99 -nostdlib $(CFLAGS_PIC16BIT)

#Debugging/Optimization
ifeq ($(DEBUG), 1)
CFLAGS += -O0 -ggdb
else
CFLAGS += -O1 -DNDEBUG
endif

LDFLAGS += --heap=0 -nostdlib -T $(XC16)/support/$(PARTFAMILY)/gld/p$(PART).gld -Map=$@.map --cref -p$(PART)
LIBS += -L$(XC16)/lib -L$(XC16)/lib/$(PARTFAMILY) -lc99 -lm -lc99-pic30

SRC = \
	main.c \

OBJ = $(addprefix $(BUILD)/, $(SRC:.c=.o) )

ifeq ($(BUILD_VERBOSE),0)
Q = @
else
Q =
endif

all: $(BUILD)/$(TARGET_NAME).hex

$(BUILD)/$(TARGET_NAME).hex: $(BUILD)/$(TARGET_NAME).elf
	@echo "Create $@"
	$(Q)$(CROSS_COMPILE)bin2hex $<

$(BUILD)/$(TARGET_NAME).elf: $(OBJ)
	@echo "LINK $@"
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(Q)size $@

$(OBJ): $(SRC)
	mkdir -p $(BUILD)
	@echo "Create $(BUILD)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(BUILD)
	@echo '$(BUILD) folder deleted'
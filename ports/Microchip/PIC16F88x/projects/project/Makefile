XCVERSION ?= 3.00

BUILD ?= build
TARGET_NAME ?= firmware

PART ?= 24FJ128GA010
PARTFAMILY = PIC24F

INC = -I.

LDFLAGS = --heap=0 -nostdlib -T

SRC = \
	main.c \

ifeq ($(OS),Windows_NT)

XC16_BASE = "C:\Program Files\Microchip\xc16\v"
XC16 = $(XC16_BASE)$(XCVERSION)
CROSS_COMPILE = $(XC16)\bin\xc16-

TARGET_PATH = $(BUILD)\$(TARGET_NAME)

INC += -I $(XC16)\include
INC += -I $(XC16)\support\$(PARTFAMILY)/h

LDFLAGS += $(XC16)\support\$(PARTFAMILY)\gld\p$(PART).gld -Map=$@.map --cref -p$(PART) --report-mem
LIBS = -L $(XC16)\lib -L $(XC16)\lib\$(PARTFAMILY) -lc99 -lm -lc99-pic30

OBJ = $(addprefix $(BUILD)\, $(SRC:.c=.o) )

MKDIR = mkdir

else	# Linux

XC16_BASE = /opt/microchip/xc16/v
XC16 = $(XC16_BASE)$(XCVERSION)
CROSS_COMPILE = $(XC16)/bin/xc16-

TARGET_PATH = $(BUILD)/$(TARGET_NAME)

INC += -I $(XC16)/include
INC += -I $(XC16)/support/$(PARTFAMILY)/h

LDFLAGS += $(XC16)/support/$(PARTFAMILY)/gld/p$(PART).gld -Map=$@.map --cref -p$(PART) --report-mem
LIBS = -L $(XC16)/lib -L $(XC16)/lib/$(PARTFAMILY) -lc99 -lm -lc99-pic30

OBJ = $(addprefix $(BUILD)/, $(SRC:.c=.o) )

MKDIR = mkdir -p

endif

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld

CFLAGS_PIC16BIT = -mcpu=$(PART) -mlarge-code
CFLAGS = $(INC) -Wall -Werror -std=gnu99 -nostdlib $(CFLAGS_PIC16BIT)

ifeq ($(DEBUG), 1)	# Debugging/Optimization
CFLAGS += -O0 -ggdb
else
CFLAGS += -O1 -DNDEBUG
endif

ifeq ($(BUILD_VERBOSE),0)
Q = @
else
Q =
endif

all: $(TARGET_PATH).hex

$(TARGET_PATH).hex: $(TARGET_PATH).elf
	@echo "Create $@"
	$(Q)$(CROSS_COMPILE)bin2hex $<

$(TARGET_PATH).elf: $(OBJ)
	@echo "Link $@"
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJ): $(SRC)
ifneq "$(wildcard $(BUILD) )" ""
	@echo "$(BUILD) folder already exists"
else
	$(MKDIR) $(BUILD)
	@echo "Create $(BUILD) folder"
endif
	$(CC) $(CFLAGS) -c $< -o $@

clean:
ifneq "$(wildcard $(BUILD) )" ""
	rm -fr $(BUILD)
	@echo "Delete $(BUILD) folder"
endif
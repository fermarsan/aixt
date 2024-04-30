XCVERSION ?= 2.10

BUILD ?= build
TARGET_NAME ?= firmware

ifeq ($(OS),Windows_NT)
XC16 = C:\Program\ Files\Microchip\xc16\v$(XCVERSION)
TARGET_PATH = $(BUILD)\$(TARGET_NAME)
CROSS_COMPILE = $(XC16)\bin\xc16-
else
XC16 = /opt/microchip/xc16/v$(XCVERSION)
TARGET_PATH = $(BUILD)/$(TARGET_NAME)
CROSS_COMPILE = $(XC16)/bin/xc16-
endif

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld

PART ?= 24FJ128GA010
PARTFAMILY = PIC24F

INC += -I.
ifeq ($(OS),Windows_NT)
INC += -I$(XC16)/include
INC += -I$(XC16)/support/$(PARTFAMILY)/h
else
INC += -I$(XC16)\include
INC += -I$(XC16)\support\$(PARTFAMILY)/h
endif

CFLAGS_PIC16BIT = -mcpu=$(PART) -mlarge-code
CFLAGS += $(INC) -Wall -Werror -std=gnu99 -nostdlib $(CFLAGS_PIC16BIT)

#Debugging/Optimization
ifeq ($(DEBUG), 1)
CFLAGS += -O0 -ggdb
else
CFLAGS += -O1 -DNDEBUG
endif

LDFLAGS += --heap=0 -nostdlib -T 
ifeq ($(OS),Windows_NT)
LDFLAGS += $(XC16)\support\$(PARTFAMILY)\gld\p$(PART).gld -Map=$@.map --cref -p$(PART)
LIBS += -L$(XC16)\lib -L$(XC16)\lib\$(PARTFAMILY) -lc99 -lm -lc99-pic30
else
LDFLAGS += $(XC16)/support/$(PARTFAMILY)/gld/p$(PART).gld -Map=$@.map --cref -p$(PART)
LIBS += -L$(XC16)/lib -L$(XC16)/lib/$(PARTFAMILY) -lc99 -lm -lc99-pic30
endif

SRC = \
	main.c \

ifeq ($(OS),Windows_NT)
OBJ = $(addprefix $(BUILD)\, $(SRC:.c=.o) )
else
OBJ = $(addprefix $(BUILD)/, $(SRC:.c=.o) )
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
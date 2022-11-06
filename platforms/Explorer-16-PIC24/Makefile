#Transpiler
AIXTT = python3 ../../base/aixtt.py
C_SOURCE = $(subst .v,.c, $(TARGET))
#Compiler
CC = /opt/microchip/xc16/v2.00/bin/xc16-gcc
CFLAGS = -mcpu=24fj128ga010
CFLAGS += -I $(CURDIR)
CFLAGS += -o $(subst .v,.hex, $(TARGET))

all: transpile compile

transpile:
	$(AIXTT) $(TARGET)

compile:
	$(CC) $(CFLAGS) $(C_SOURCE) 
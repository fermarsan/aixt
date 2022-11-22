#Transpiler
AIXTT = python3 ../../base/aixtt.py
C_SOURCE = $(subst .v,.c, $(TARGET))
#Compiler
XC16 = /opt/microchip/xc16/v2.00
PARTFAMILY = PIC24F
CC = $(XC16)/bin/xc16-gcc
INC += -I $(CURDIR)
INC += -I ../../api/Explorer-16-PIC24
INC += -I $(XC16)/include
INC += -I $(XC16)/support/$(PARTFAMILY)/h
OBJ += -o $(subst .v,.hex, $(TARGET))
CFLAGS = -mcpu=24fj128ga010 $(INC) $(OBJ)

all: transpile compile

transpile:
	$(AIXTT) $(TARGET)

compile:
	$(CC) $(CFLAGS) $(C_SOURCE) 
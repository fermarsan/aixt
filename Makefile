TARGET = ./aixt

VC = v

VFLAGS = -o

SOURCE = ./src

$(TARGET): $(SOURCE)
	$(VC) $(VFLAGS) $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)
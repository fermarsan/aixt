TARGET = ./aixt

VC = v

VFLAGS = -o

SOURCE = ./src

$(TARGET): $(SOURCE)
	$(VC) $(VFLAGS) $(TARGET) $(SOURCE)
	@echo "aixt executable created"

clean:
	rm -f $(TARGET)
	@echo "aixt executable deleted"
TARGET = ./aixt

VC = v

VFLAGS = -o

SOURCE = ./src

$(TARGET): $(SOURCE)
	$(VC) $(VFLAGS) $(TARGET) $(SOURCE)
	@echo "Aixt executable created"

clean:
	rm -f $(TARGET)
	@echo "Aixt executable deleted"
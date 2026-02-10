TARGET = ./aixt

VC = v

VFLAGS = -o

SOURCE = ./src

$(TARGET): $(SOURCE)
	$(VC) $(VFLAGS) $(TARGET) $(SOURCE)
	@echo "Aixt executable created"

static:
	$(VC) -prod -cflags '-static' $(VFLAGS) $(TARGET) $(SOURCE)
	@echo "Aixt static executable created"

clean:
	rm -f $(TARGET)
	@echo "Aixt executable deleted"
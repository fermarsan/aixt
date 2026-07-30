OUTPUT_FOLDER = ./build

TARGET = $(OUTPUT_FOLDER)/aixt

VC = v #~/v_050/v

VFLAGS = -o

SOURCE = ./src

$(TARGET): $(SOURCE)
	mkdir -pv $(OUTPUT_FOLDER)
	$(VC) $(VFLAGS) $(TARGET) $(SOURCE)
	@echo "The Aixt executable was created at /build folder"

static:
	$(VC) -prod -cflags '-static' $(VFLAGS) $(TARGET) $(SOURCE)
	@echo "The Aixt executable was created at /build folder"

clean:
	rm -f $(TARGET)
	rmdir $(OUTPUT_FOLDER)
	@echo "The Aixt executable was deleted"
ifeq ($(PLATFORM), Windows)
	CFLAGS = -O2 --std=c++20 -g
	LDFLAGS = -static -Wall -Iexternal -DPLATFORM_DESKTOP -lopengl32 -lraylib -lgdi32 -lwinmm -lpthread
	COMP = g++.exe
	BUILD_DIR = Build
else
	CFLAGS = -O2 --std=c++20 -g
    LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    COMP = g++
    BUILD_DIR = Build
endif

$(shell mkdir -p $(BUILD_DIR))

OBJS = $(BUILD_DIR)/CContra.o 

all: $(BUILD_DIR)/CContra

$(BUILD_DIR)/CContra: $(OBJS)
	$(COMP) $(OBJS) -o CContra $(CFLAGS) $(LDFLAGS)

$(BUILD_DIR)/CContra.o: Source/CContra.cpp  Source/*.hpp
	$(COMP) $(CFLAGS) -c Source/CContra.cpp -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o CContra CContra.exe 

# Target to run clang-format on all C++ files
.PHONY: format

format:
	clang-format -i Source/*.cpp Source/*.hpp 

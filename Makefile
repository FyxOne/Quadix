CXX := g++
CXXFLAGS := -std=c++17 -Ilibs/include -Wall -Wextra -g -DSFML_STATIC
LDFLAGS := -Llibs/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lws2_32

SRC_DIR := source
OBJ_DIR := build
BIN_DIR := bin

TARGET := $(BIN_DIR)/quadix

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS) build_res
	@mkdir -p $(BIN_DIR) 
	$(CXX) $(OBJS) logo.res version.res -o $@ $(LDFLAGS) -Wunused-parameter

	rm *.res

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp build_res
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) logo.res version.res -c $< -o $@ -Wunused-parameter

build_res:
	windres logo.rc -O coff -o logo.res
	windres version.rc -O coff -o version.res

clean:
	rm -rf $(OBJ_DIR)

rebuild: clean all

.PHONY: all clean rebuild
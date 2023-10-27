SHELL := /bin/bash
CXX := g++ 
CXX_VERSION = -std=c++11
CXX_DEBUG := -g
CXX_WARNINGS := -Wall
CXX_OPT_FLAGS := -Og -flto
CXX_PFM := -lpfm
CXX_LIBS := -fopenmp
CXX_PGO_GENERATE := -fprofile-generate 
CXX_FLAGS :=  $(CXX_OPT_FLAGS) $(CXX_VERSION) $(CXX_DEBUG) $(CXX_WARNINGS) $(CXX_LIBS) 

BIN := ./bin
SRC := ./src
OBJ := $(BIN)/obj
SANDBOX := ./sandbox
SANDBOX_DIR := ./sandbox/proj1 

# CORE Directories for source and header files
SRC_DIR := ./src
CORE_DIR := $(SRC_DIR)/core
EVENTS_DIR := $(CORE_DIR)/events
CORE_PROFILING := $(CORE_DIR)/profiling
PLATFORMS_DIR := $(SRC_DIR)/platforms
IMGUI_OPENGL_DIR := $(PLATFORMS_DIR)/imgui_opengl3_glfw
UTILS_DIR := $(SRC_DIR)/utils
DEPLOYTMENT_DIR := $(UTILS_DIR)/deployment
LOGGING_DIR := $(UTILS_DIR)/logging
OPTIMIZATIONS_DIR := $(UTILS_DIR)/optimizations
PROFILING_DIR := $(UTILS_DIR)/profiling
 
# LIB Directories for source and header files
LIB_SPD_PATH :=./lib/spdlog
LIB_SPD := -I./lib/spdlog/include/  -I./lib/spdlog/include/spdlog 

LIB_GLEW_PATH := ./lib/glew
LIB_GLEW := -I./lib/glew/include/ -I./lib/spdlog/include/glew 

LIB_GLFW_PATH := ./lib/glfw
LIB_GLFW := -I./lib/glfw/include/ -I./lib/spdlog/include/glfw
  
LIB_IMGUI_PATH := ./lib/imgui
LIB_IMGUI := -I./lib/imgui/ -I./lib/imgui/backends -I./lib/imgui/docs -I./lib/imgui/examples -I./lib/imgui/mics

LIB_IMPLOT_PATH := ./lib/implot 
LIB_IMPLOT := -I./lib/implot/

LIB_PFM_PATH := ./lib/libpfm4


DYNAMIC := -L$(LIB_SPD_PATH)/build/ -lspdlog -L$(LIB_GLFW_PATH)/build/src/ -lglfw3 -L$(LIB_GLEW_PATH)/lib/ -lGLEW -lGL

# Include directories
INCLUDE := -I$(SRC_DIR)\
           -I$(CORE_DIR)\
		   -I$(EVENTS_DIR)\
		   -I$(CORE_PROFILING)\
           -I$(PLATFORMS_DIR)\
           -I$(IMGUI_OPENGL_DIR)\
           -I$(UTILS_DIR)\
           -I$(DEPLOYTMENT_DIR)\
		   -I$(PROFILING_DIR)\
		   -I$(LOGGING_DIR)\
           -I$(OPTIMIZATIONS_DIR)\
			$(LIB_SPD)\
			$(LIB_GLEW)\
			$(LIB_GLFW)\
			$(LIB_IMGUI)\
			$(LIB_IMPLOT)

EXECUTABLE := optimizer_toolkit.core

SRC_FILES := $(shell find $(SRC) -type f -name "*.cc") $(shell find $(SANDBOX) -type f -name "*.cc")
OBJ_FILES := $(patsubst ./%.cc,$(OBJ)/%.o,$(SRC_FILES)) 
 
all: ${LIB_IMGUI_PATH}/build $(LIB_SPD_PATH)/build/libspdlog.a $(LIB_GLFW_PATH)/build/src/libglfw3.a $(LIB_GLEW_PATH)/lib/libGLEW.a ${LIB_PFM_PATH}/all_set ${EVENTS_DIR}/all_set $(BIN)/$(EXECUTABLE) $(BIN)/optimizer_toolkit.desktop 
	@if [ ! -d "$(BIN)/fonts" ]; then \
        mkdir -p "$(BIN)/fonts"; \
        cp -R ./lib/fonts/* "$(BIN)/fonts"; \
        echo "Fonts installed successfully!"; \
    else \
        echo "Fonts directory already exists. Skipping installation."; \
    fi
 
## check memory if there're any leaks.
mem_check:
	cd $(BIN) && valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

## create a desktop file and move it to applications
$(BIN)/optimizer_toolkit.desktop:
	echo -e "[Desktop Entry]\n\
Version=1.0\n\
Type=Application\n\
Terminal=true\n\
Name=Optimizer Toolkit\n\
Path=$(shell pwd)/bin/\n\
Exec=$(shell pwd)/bin/$(EXECUTABLE)\n\
Icon=$(shell pwd)/icon/icon.png\n" > $(BIN)/optimizer_toolkit.desktop

	cp $(BIN)/optimizer_toolkit.desktop ~/.local/share/applications

$(LIB_GLEW_PATH)/lib/libGLEW.a:
	cd $(LIB_GLEW_PATH) && ./install.sh
	
$(LIB_SPD_PATH)/build/libspdlog.a:
	cd $(LIB_SPD_PATH) && ./install.sh

$(LIB_GLFW_PATH)/build/src/libglfw3.a:
	cd $(LIB_GLFW_PATH) && ./install.sh

${LIB_IMGUI_PATH}/build:
	cd ${LIB_IMGUI_PATH} && ./install.sh

${LIB_PFM_PATH}/all_set:
	cd ${LIB_PFM_PATH} && ./install.sh

run: all
	@echo "🚀 Executing..."
	cd $(BIN); ./$(EXECUTABLE)

${EVENTS_DIR}/all_set:
	@echo "⛏️ Exporting events from libpfm4"
	cd $(UTILS_DIR) && python3 pmu_parser.py $(shell find ${LIB_PFM_PATH}/lib/events -type f -name "*.h" -exec echo "../../{}" \;)

clean_run: clean all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJ_FILES)
	echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) $^ -o ./$(BIN)/$(EXECUTABLE) ${LIB_IMGUI_PATH}/build/*.o $(INCLUDE) $(DYNAMIC) $(CXX_PFM) 

$(OBJ)/%.o: ./%.cc
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -c -o $@ $< $(INCLUDE) $(CXX_PFM) 

clean: 
	rm -rf $(BIN)/*
	rm -rf ~/.local/share/applications/optimizer_toolkit.desktop ## remove dekstop icon
	@echo "🧹 Bin Directory cleaned!"

clean_events:
	rm -rf ${EVENTS_DIR}/*
	@echo "🧹 Events cleaned!"

clean_libs:
	cd $(LIB_GLEW_PATH) && ./install.sh clean
	cd $(LIB_GLFW_PATH) && ./install.sh clean
	cd ${LIB_IMGUI_PATH} && ./install.sh clean
	cd $(LIB_SPD_PATH) && ./install.sh clean 
	cd $(LIB_PFM_PATH) && ./install.sh clean 
	@echo "🧹 Libraries cleaned!"

clean_all: clean clean_events clean_libs
	@echo "🧹 Everything is cleaned"

## THESE ARE FOR MONITORING
CALL_STACK_METHOD := lbr
monitor_callstack: $(BIN)/$(EXECUTABLE)
	cd $(BIN);\
	sudo perf record --call-graph $(CALL_STACK_METHOD) ./$(EXECUTABLE);\ ## sampling
	sudo chmod a+rwx perf*;\
	sudo perf report;

tma_analysis:
	cd ./"$(BIN)";\
	sudo perf stat --topdown -a --td-level 0 -- taskset -c 0  ./$(EXECUTABLE); ## counting


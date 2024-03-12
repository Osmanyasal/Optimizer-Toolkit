SHELL := /bin/bash
CXX := g++
CXX_VERSION = -std=c++11
CXX_DEBUG := -g
CXX_WARNINGS := -Wall
CXX_OPT_FLAGS := -O3 -flto -msse -march=native -mavx2
CXX_PFM := -lpfm
CXX_LIBS := -fopenmp
CXX_PGO_GENERATE := -fprofile-generate
CXX_FLAGS :=  $(CXX_OPT_FLAGS) $(CXX_VERSION) $(CXX_DEBUG) $(CXX_WARNINGS) $(CXX_LIBS)

DOXYGEN_CONFIG_FILE := ./doxyfile
DOXYGEN_OUT_FOLDER := ./doc/

BIN := ./bin
SRC := ./src
OBJ := $(BIN)/obj

# CORE Directories for source and header files
SRC_DIR := ./src
EXAMPLES_DIR := ./examples
CORE_DIR := $(SRC_DIR)/core
CORE_EVENTS_DIR := $(CORE_DIR)/events
CORE_PROFILING := $(CORE_DIR)/profiling
CORE_RECIPIES := $(CORE_DIR)/recipies

PROFILING_RAPL := $(CORE_PROFILING)/rapl
PROFILING_PMU := $(CORE_PROFILING)/pmu

RECIPIE_RAPL := $(CORE_RECIPIES)/rapl
RECIPIE_PMU := $(CORE_RECIPIES)/pmu

PLATFORMS_DIR := $(SRC_DIR)/platforms
IMGUI_OPENGL_DIR := $(PLATFORMS_DIR)/imgui_opengl3_glfw
CHARTS := $(PLATFORMS_DIR)/charts
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
LIB_PFM := -I./lib/libpfm4/include/perfmon/ -I./lib/libpfm4/lib/

DYNAMIC_LIBS := -L$(LIB_SPD_PATH)/build/ -lspdlog -L$(LIB_GLFW_PATH)/build/src/ -lglfw3 -L$(LIB_GLEW_PATH)/lib/ -lGLEW -lGL -ldl

# Include directories
INCLUDE := -I$(SRC_DIR)\
		   -I$(EXAMPLES_DIR)\
           -I$(CORE_DIR)\
		   -I$(CORE_EVENTS_DIR)\
		   -I$(CORE_PROFILING)\
		   -I$(CORE_RECIPIES)\
		   -I$(RECIPIE_PMU)\
		   -I$(RECIPIE_RAPL)\
		   -I$(PROFILING_PMU)\
		   -I$(PROFILING_RAPL)\
           -I$(PLATFORMS_DIR)\
           -I$(CHARTS)\
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
			$(LIB_IMPLOT)\
			$(LIB_PFM)

EXECUTABLE := optimizer_toolkit.core
STATIC_LIB := liboptkit.a
DYNAMIC_LIB := liboptkit.so

SRC_FILES := $(shell find $(SRC) -type f -name "*.cc") $(shell find $(EXAMPLES_DIR) -type f -name "*.cc")
OBJ_FILES := $(patsubst ./%.cc,$(OBJ)/%.o,$(SRC_FILES))

all: $(LIB_GLEW_PATH)/lib/libGLEW.a $(LIB_GLFW_PATH)/build/src/libglfw3.a ${LIB_PFM_PATH}/all_set ${LIB_IMGUI_PATH}/build $(LIB_SPD_PATH)/build/libspdlog.a ${CORE_EVENTS_DIR}/all_set $(BIN)/$(EXECUTABLE) $(BIN)/$(STATIC_LIB)
	@if [ ! -d "$(BIN)/fonts" ]; then \
        mkdir -p "$(BIN)/fonts"; \
        cp -R ./lib/fonts/* "$(BIN)/fonts"; \
        echo "Fonts installed successfully!"; \
    else \
        echo "Fonts directory already exists. Skipping installation."; \
    fi


################ BUILD COMMANDS ################


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
	@clear
	@echo "🚀 Executing..."
	cd $(BIN); ./$(EXECUTABLE)

${CORE_EVENTS_DIR}/all_set:
	@echo "⛏️ Exporting events from libpfm4"
	cd $(UTILS_DIR) && python3 pmu_parser.py $(shell find ${LIB_PFM_PATH}/lib/events -type f \( -name "intel*.h" -or -name "amd*.h" -or -name "arm*.h" -or -name "power*.h" \) -exec echo "../../{}" \;)

clean_run: clean all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJ_FILES)
	echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) $^ -o ./$(BIN)/$(EXECUTABLE) ${LIB_IMGUI_PATH}/build/*.o $(INCLUDE) $(DYNAMIC_LIBS) $(CXX_PFM)

$(BIN)/$(STATIC_LIB): $(OBJ_FILES)
	echo "🚧 creating static library..."
	ar rcs ./$(BIN)/$(STATIC_LIB) $^  ${LIB_IMGUI_PATH}/build/*.o

$(BIN)/$(DYNAMIC_LIB): $(OBJ_FILES)
	echo "🚧 dynamic library disabled!"
	#$(CXX) $(CXX_FLAGS) -shared -fPIC $^ -o ./$(BIN)/$(DYNAMIC_LIB) ${LIB_IMGUI_PATH}/build/*.o $(INCLUDE) $(DYNAMIC_LIBS) $(CXX_PFM)

$(OBJ)/%.o: ./%.cc
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -c -o $@ $< $(INCLUDE) $(CXX_PFM)

#----------------------------------------------------



################ INSTALL COMMANDS ################

install: all install_headers install_library install_sandbox
	echo -e "[Desktop Entry]\n\
Version=1.0\n\
Type=Application\n\
Terminal=true\n\
Name=Optimizer Toolkit\n\
Path=$(shell pwd)/bin/\n\
Exec=$(shell pwd)/bin/$(EXECUTABLE)\n\
Icon=$(shell pwd)/icon/icon.png\n" > $(BIN)/optimizer_toolkit.desktop

	cp $(BIN)/optimizer_toolkit.desktop ~/.local/share/applications

install_headers:
	sudo mkdir -p /usr/local/include/optkit/
	sudo find ./src/ -type f -name "*.h*" -exec cp {} "/usr/local/include/optkit/" \;


install_library:
	sudo cp -R ./bin/liboptkit.a ./bin/fonts /usr/local/lib

install_sandbox:
	cd sandbox && ./install.sh

#----------------------------------------------------



################ GEN DOCS COMMANDS ################

doc_build:
	@doxygen ${DOXYGEN_CONFIG_FILE}

doc_clean:
	@rm -rf ${DOXYGEN_OUT_FOLDER}
#----------------------------------------------------




################ CLEAN COMMANDS ################
clean:
	rm -rf $(BIN)/*
	rm -rf ~/.local/share/applications/optimizer_toolkit.desktop ## remove dekstop icon
	@echo "🧹 Bin Directory cleaned!"

clean_events:
	rm -rf ${CORE_EVENTS_DIR}/*
	@echo "🧹 Events cleaned!"

clean_libs:
	cd $(LIB_GLEW_PATH) && ./install.sh clean
	cd $(LIB_GLFW_PATH) && ./install.sh clean
	cd ${LIB_IMGUI_PATH} && ./install.sh clean
	cd $(LIB_SPD_PATH) && ./install.sh clean
	cd $(LIB_PFM_PATH) && ./install.sh clean
	@echo "🧹 Libraries cleaned!"

clean_all: clean clean_events clean_libs doc_clean
	@echo "🧹 Everything is cleaned"
#----------------------------------------------------




################ MONITORING COMMANDS ################

## check memory if there're any leaks.
mem_check:
	cd $(BIN) && valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

CALL_STACK_METHOD := lbr
monitor_callstack: $(BIN)/$(EXECUTABLE)
	cd $(BIN);\
	sudo perf record --call-graph $(CALL_STACK_METHOD) ./$(EXECUTABLE);\ ## sampling
	sudo chmod a+rwx perf*;\
	sudo perf report;

tma_analysis:
	cd ./"$(BIN)";\
	sudo perf stat --topdown -a --td-level 0 -- taskset -c 0  ./$(EXECUTABLE); ## counting

#----------------------------------------------------

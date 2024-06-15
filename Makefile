SHELL := /bin/bash
CXX := g++
CXX_VERSION = -std=c++11
CXX_DEBUG := -g
CXX_WARNINGS := -Wall
CXX_OPT_FLAGS := -O0 -msse -march=native -mavx2
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
TEST_DIR := ./test
CORE_DIR := $(SRC_DIR)/core
CORE_EVENTS_DIR := $(CORE_DIR)/events

CORE_EVENTS_INTEL_DIR   := $(CORE_EVENTS_DIR)/intel
CORE_EVENTS_AMD64_DIR   := $(CORE_EVENTS_DIR)/amd64
CORE_EVENTS_ARM_DIR     := $(CORE_EVENTS_DIR)/arm
CORE_EVENTS_POWER4_DIR  := $(CORE_EVENTS_DIR)/power4
CORE_EVENTS_POWER5_DIR  := $(CORE_EVENTS_DIR)/power5
CORE_EVENTS_POWER5P_DIR := $(CORE_EVENTS_DIR)/power5p
CORE_EVENTS_POWER6_DIR  := $(CORE_EVENTS_DIR)/power6
CORE_EVENTS_POWER7_DIR  := $(CORE_EVENTS_DIR)/power7
CORE_EVENTS_POWER8_DIR  := $(CORE_EVENTS_DIR)/power8
CORE_EVENTS_POWER9_DIR  := $(CORE_EVENTS_DIR)/power9
CORE_EVENTS_POWER10_DIR  := $(CORE_EVENTS_DIR)/power10
CORE_EVENTS_POWERPC_DIR := $(CORE_EVENTS_DIR)/powerpc

CORE_EVENT_RECEPIES_DIR := $(CORE_DIR)/event_recepies
CORE_EVENT_RECEPIES_INTEL_ICL_DIR := $(CORE_DIR)/event_recepies/intel/icl
CORE_EVENT_RECEPIES_INTEL_SKL_DIR := $(CORE_DIR)/event_recepies/intel/skl
CORE_EVENT_RECEPIES_INTEL_BDW_DIR := $(CORE_DIR)/event_recepies/intel/bdw
CORE_EVENT_RECEPIES_AMD_ZEN3_DIR := $(CORE_DIR)/event_recepies/amd/zen3


CORE_PROFILING := $(CORE_DIR)/profiling
CORE_FREQUENCY := $(CORE_DIR)/freq
CORE_RECIPIES := $(CORE_DIR)/recipies

PROFILING_RAPL := $(CORE_PROFILING)/rapl
PROFILING_PMU := $(CORE_PROFILING)/pmu

RECIPIE_RAPL := $(CORE_RECIPIES)/rapl
RECIPIE_PMU := $(CORE_RECIPIES)/pmu

UTILS_DIR := $(SRC_DIR)/utils
DEPLOYTMENT_DIR := $(UTILS_DIR)/deployment
LOGGING_DIR := $(UTILS_DIR)/logging
OPTIMIZATIONS_DIR := $(UTILS_DIR)/optimizations
PROFILING_DIR := $(UTILS_DIR)/profiling

# LIB Directories for source and header files
LIB_SPD_PATH :=./lib/spdlog
LIB_SPD := -I./lib/spdlog/include/  -I./lib/spdlog/include/spdlog

LIB_X86_ADAPT_PATH :=./lib/x86_adapt 

LIB_PFM_PATH := ./lib/libpfm4
LIB_PFM := -I./lib/libpfm4/include/perfmon/ -I./lib/libpfm4/lib/
 
# Determine architecture
ARCH := $(shell uname -m)

# Define the dynamic libraries for Intel systems
INTEL_LIBS := -lx86_adapt

# Conditionally link x86_adapt only on Intel systems
ifeq ($(ARCH), x86_64)
    DYNAMIC_LIBS := -L$(LIB_SPD_PATH)/build/ -lspdlog -ldl #$(INTEL_LIBS)
else
    DYNAMIC_LIBS := -L$(LIB_SPD_PATH)/build/ -lspdlog -ldl
endif


# Include directories
INCLUDE := -I$(SRC_DIR)\
		   -I$(TEST_DIR)\
           -I$(CORE_DIR)\
		   -I$(CORE_EVENT_RECEPIES_DIR)\
		   -I$(CORE_EVENT_RECEPIES_INTEL_ICL_DIR)\
		   -I$(CORE_EVENT_RECEPIES_INTEL_SKL_DIR)\
		   -I$(CORE_EVENT_RECEPIES_INTEL_BDW_DIR)\
		   -I$(CORE_EVENT_RECEPIES_AMD_ZEN3_DIR)\
		   -I$(CORE_EVENTS_DIR)\
		   -I$(CORE_EVENTS_INTEL_DIR)\
		   -I$(CORE_EVENTS_AMD64_DIR)\
		   -I$(CORE_EVENTS_ARM_DIR)\
		   -I$(CORE_EVENTS_POWER4_DIR)\
		   -I$(CORE_EVENTS_POWER5_DIR)\
		   -I$(CORE_EVENTS_POWER5P_DIR)\
		   -I$(CORE_EVENTS_POWER6_DIR)\
		   -I$(CORE_EVENTS_POWER7_DIR)\
		   -I$(CORE_EVENTS_POWER8_DIR)\
		   -I$(CORE_EVENTS_POWER9_DIR)\
		   -I$(CORE_EVENTS_POWER10_DIR)\
		   -I$(CORE_EVENTS_POWERPC_DIR)\
		   -I$(CORE_PROFILING)\
		   -I$(CORE_FREQUENCY)\
		   -I$(CORE_RECIPIES)\
		   -I$(RECIPIE_PMU)\
		   -I$(RECIPIE_RAPL)\
		   -I$(PROFILING_PMU)\
		   -I$(PROFILING_RAPL)\
           -I$(UTILS_DIR)\
           -I$(DEPLOYTMENT_DIR)\
		   -I$(PROFILING_DIR)\
		   -I$(LOGGING_DIR)\
           -I$(OPTIMIZATIONS_DIR)\
			$(LIB_SPD)\
			$(LIB_PFM)

EXECUTABLE := optimizer_toolkit.core
STATIC_LIB := liboptkit.a
DYNAMIC_LIB := liboptkit.so

SRC_FILES := $(shell find $(SRC) -type f -name "*.cc") $(shell find $(TEST_DIR) -type f -name "*.cc")
OBJ_FILES := $(patsubst ./%.cc,$(OBJ)/%.o,$(SRC_FILES))

all: ${LIB_PFM_PATH}/all_set $(LIB_SPD_PATH)/build/libspdlog.a ${CORE_EVENTS_DIR}/all_set $(BIN)/$(EXECUTABLE) $(BIN)/$(STATIC_LIB) ## ${LIB_X86_ADAPT_PATH}/all_set 
	 


################ BUILD COMMANDS ################


$(LIB_SPD_PATH)/build/libspdlog.a:
	cd $(LIB_SPD_PATH) && ./install.sh

${LIB_PFM_PATH}/all_set:
	cd ${LIB_PFM_PATH} && ./install.sh

run: all
	@clear
	@echo "🚀 Executing..."
	cd $(BIN); ./$(EXECUTABLE)

${CORE_EVENTS_DIR}/all_set:
	@echo "⛏️ Exporting events from libpfm4"
	cd $(UTILS_DIR) && python3 pmu_parser.py $(shell find ${LIB_PFM_PATH}/lib/events -type f \( -name "intel*.h" -or -name "amd*.h" -or -name "arm*.h" -or -name "power*.h" \) -exec echo "../../{}" \;)

${LIB_X86_ADAPT_PATH}/all_set:
	@echo "⛏️ Building x86 adapt library"
	cd $(LIB_X86_ADAPT_PATH) && ./install.sh

clean_run: clean all
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJ_FILES)
	echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) $^ -o ./$(BIN)/$(EXECUTABLE) $(INCLUDE) $(DYNAMIC_LIBS) $(CXX_PFM)

$(BIN)/$(STATIC_LIB): $(OBJ_FILES)
	echo "🚧 creating static library..."
	gcc-ar rcs ./$(BIN)/$(STATIC_LIB) $^ 
	gcc-ranlib ./$(BIN)/$(STATIC_LIB)

$(BIN)/$(DYNAMIC_LIB): $(OBJ_FILES)
	echo "🚧 dynamic library disabled!"
	#$(CXX) $(CXX_FLAGS) -shared -fPIC $^ -o ./$(BIN)/$(DYNAMIC_LIB) $(INCLUDE) $(DYNAMIC_LIBS) $(CXX_PFM)

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
	sudo find ./src/ -type f -name "*.hh" -exec cp {} "/usr/local/include/optkit/" \;


install_library:
	sudo cp -R ./bin/liboptkit.a /usr/local/lib

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

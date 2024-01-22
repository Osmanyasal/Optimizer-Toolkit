#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__UTILS__UTILS
#define OPTIMIZER_TOOLKIT_CORE__SRC__UTILS__UTILS
/*
    All header files that's defined in utils.
    to access utils include this file
*/
#include <algorithm>
#include <cstdint>
#include <random>
#include <sys/stat.h>

// CUSTOM HEADERS
#include <logger.hh>
#include <type.hh>

// TODO: Migrate this to a math wrapper.
//  INCLUDE GLM
#include <glm_utils.hh>

// OPTIMIZATION HEADERS
#include <cpu_opt.hh>

// PROFILING HEADERS
#include <block_timer.hh>
#include <gantt_instrumentor.hh>

#include <dirent.h>

// MACRO DEFINITIONS
#define BIT(x) (1 << x)
 
#define BLOCK_TIMER(block_name) \
    OPTKIT::utils::BlockTimer block_timer { block_name }

// GLOBAL VARIABLES

extern std::string EXECUTION_FOLDER_NAME;

// FUNCTION DECLERATIONS
std::string generateGUID();

std::string read_file(const std::string &location, bool is_verbose = true);
void write_file(const std::string &location, const std::string &json_val, bool is_verbose = false);
bool is_path_exists(const std::string &location);

void create_directory(const std::string &folderName);
std::string get_date(const std::string &format = "%d_%m_%Y");
std::string get_time(const std::string &format = "%H_%M_%S");
std::vector<std::string> get_all_files(const std::string &directory_name);

#endif
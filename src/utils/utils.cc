#include <utils.hh>

const std::string EXECUTION_FOLDER_NAME{get_date() + "__" + get_time() + "__" + generateGUID().substr(0, CONF__LOG__PRINT_GUID_LENGTH)};

std::string generateGUID()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis(0, 0xFFFFFFFFFFFFFFFF);

    std::stringstream ss;
    ss << std::hex << std::setfill('0');

    // Generate first part (8 digits)
    ss << std::setw(8) << dis(gen);

    // Generate second part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate third part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate fourth part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate fifth part (12 digits)
    ss << '-';
    ss << std::setw(12) << dis(gen);
    return ss.str();
}

std::string read_file(const std::string &location, bool is_verbose)
{
    std::stringstream buffer;
    std::ifstream file(location);
    if (OPT_UNLIKELY(is_verbose && !file.is_open()))
    {
        OPTKIT_CORE_ERROR("file not found at the location {}", location);
        throw std::runtime_error("Failed to open the file: " + location);
    }
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}

void write_file(const std::string &location, const std::string &json_val, bool is_verbose)
{
    std::ofstream file(location, std::ios_base::out | std::ios_base::app); // create & append mode
    if (OPT_UNLIKELY(is_verbose && !file.is_open()))
    {
        OPTKIT_CORE_ERROR("Failed to open the file for writing: {}", location);
        throw std::runtime_error("Failed to open the file for writing: " + location);
    }

    file << json_val << "\n";
    file.close();

    if (is_verbose)
    {
        OPTKIT_CORE_INFO("JSON data successfully written to file: {}", location);
    }
}

bool is_path_exists(const std::string &location)
{
    struct stat buffer;
    return (stat(location.c_str(), &buffer) == 0);
}

void create_directory(const std::string &folderName)
{
#ifdef _WIN32
    // For Windows
    if (_mkdir(folderName.c_str()) != 0)
    {
        OPTKIT_CORE_ERROR("Error creating directory {}", folderName);
        exit(EXIT_FAILURE);
    }
#else
    // For Linux/Unix
    if (mkdir(folderName.c_str(), 0777) != 0)
    {
        OPTKIT_CORE_ERROR("Error creating directory {}", folderName);
        exit(EXIT_FAILURE);
    }
#endif
}

std::string get_date(const std::string &format)
{
    // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Convert the time point to a time_t object
    auto currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert the time_t object to a tm struct
    std::tm *localTime = std::localtime(&currentTime);

    // Format the date using the provided format
    std::ostringstream oss;
    oss << std::put_time(localTime, format.c_str());

    return oss.str();
}
std::string get_time(const std::string &format)
{
    // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Convert the time point to a time_t object
    auto currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert the time_t object to a tm struct
    std::tm *localTime = std::localtime(&currentTime);

    // Format the time using the provided format
    std::ostringstream oss;
    oss << std::put_time(localTime, format.c_str());

    return oss.str();
}
#include <utils.hh>

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
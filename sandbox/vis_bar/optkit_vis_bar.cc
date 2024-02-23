#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <optkit.hh>

int32_t main(int32_t argc, char **argv)
{
    optkit::utils::logger::BaseLogger::init();
    std::vector<std::string> file_names;
    
    if(argc < 2)
    {
        OPTKIT_ERROR("Usage {} <file_or_folder_names>", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; ++i)
    {
        // Check if the argument is a file or folder
        bool isFolder = false;
        FILE *file = fopen(argv[i], "r");
        if (file)
        {
            // It's a file
            fclose(file);
            // If it's a file, check if it matches the *.json pattern
            if (strstr(argv[i], ".json") != nullptr)
                file_names.push_back(argv[i]);
            else
            {
                OPTKIT_WARN("{} is not .json file!!", argv[i]);
                // If it's a folder, use the find command to search for *.json files recursively
                std::string command = "find " + std::string(argv[i]) + " -name \"*.json\" | sort";
                FILE *findPipe = popen(command.c_str(), "r");
                if (!findPipe)
                {
                    OPTKIT_ERROR("Error executing find command.");
                    exit(1);
                }

                char buffer[256];
                while (fgets(buffer, sizeof(buffer), findPipe) != nullptr)
                {
                    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
                    file_names.push_back(buffer);
                }
                int status = pclose(findPipe);
                if (status == -1)
                {
                    OPTKIT_ERROR("Error closing find command.");
                    exit(1);
                }
            }
        }
    }

    std::cout << "FOUNT FILES!!\n";
    OPTKIT_INFO("---- FOUND FILES -----");
    for (const std::string &file : file_names)
    {
        OPTKIT_INFO("{}", file);
    }

    EXECUTION_FOLDER_NAME = ".";
    OptimizerKit::draw(file_names);

    return 0;
}
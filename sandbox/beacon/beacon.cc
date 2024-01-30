#include <iostream>
#include <optkit.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    int value = argc > 1 ? std::atoi(argv[1]) : -1;
    OPTKIT_INFO("Monitoring socket energy for {} sec. (-1 means indefinite)", value);
 
    RaplProfiler main_block{"main_block"};
    if (value == -1)
        while (true)
        {
            std::cout << main_block.read().second << "\n";
            sleep(1);
        }
    else
    {
        while(value-- >= 0){
            std::cout << main_block.read().second << "\n";
            sleep(1);
        }
    }

    return 0;
}
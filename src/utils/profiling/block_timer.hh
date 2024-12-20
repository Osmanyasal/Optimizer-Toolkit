#pragma once

#include <logger.hh>
#include <string>
#include <chrono> 

namespace optkit::utils
{
    class BlockTimer
    {
    public:
        BlockTimer(const std::string& block_name);
        ~BlockTimer();

    private:
        const std::string block_name;
        std::chrono::high_resolution_clock::time_point start;
    };

} // namespace optkit::utils

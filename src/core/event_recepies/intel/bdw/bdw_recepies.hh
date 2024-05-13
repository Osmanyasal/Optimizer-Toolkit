#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__BDW__BDW_RECEPIES__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__BDW__BDW_RECEPIES__HH

#include <vector>
#include <string>
#include <bdw.hh>

namespace optkit::core::recepies::intel::bdw
{
    class Recepies final
    {
    public:
        static const std::vector<std::pair<uint64_t, std::string>> computational_intensity();
        // static const std::vector<std::pair<uint64_t, std::string>> computational_intensity();

    private:
        Recepies() = delete;
        ~Recepies() = delete;
    };
}

#endif
#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__BASE_RECEPIE__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__BASE_RECEPIE__HH

#include <string>
#include <vector>
#include <cstdint>

namespace optkit::core::recepies::base
{

    /**
     * @brief This class must be implemented by general recepies which also be implemented for each cpu architectures
     *
     */
    class BaseRecepie
    {
    public:
        BaseRecepie(){};
        virtual ~BaseRecepie(){};

        /**
         * @brief each uint64_t variable represents a different PMU event with corresponding name.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual const std::vector<std::pair<uint64_t, std::string>> get_recepies() = 0;
    };

    class ComputationalIntensity : public BaseRecepie
    {
        public:
            ComputationalIntensity(){}
            virtual ~ComputationalIntensity(){}
    };

} // namespace optkit::core::recepies::bae

#endif
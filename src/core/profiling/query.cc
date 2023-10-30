
#include <query.hh>

std::ostream &operator<<(std::ostream &out, const pfm_pmu_info_t &pmu_info)
{

    // Calculate the number of spaces needed for "Information" label and vertical bars
    int horizontalLineWidth = 45; // Width of the horizontal line
    int informationWidth = horizontalLineWidth - 2; // 2 is for the two vertical bars
    int paddingWidth = (informationWidth - 16) / 2; // 16 is for the "PMU Information" label
 
    // Output the top horizontal line
    out << std::string(horizontalLineWidth, '-') << "\n";

    out << "| ";

    // Print padding before "Information" label
    out << std::setw(paddingWidth) << " ";
    out << "PMU Information";

    // Print padding after "Information" label
    out << std::setw(paddingWidth) << " ";

    out << " |\n";

    // Output the middle horizontal line
    out << std::string(horizontalLineWidth, '-') << "\n";

    out << "| " << std::setw(16) << "name:" << std::setw(25) << pmu_info.name << " |\n";
    out << "| " << std::setw(16) << "desc:" << std::setw(25) << pmu_info.desc << " |\n";
    out << "| " << std::setw(16) << "size:" << std::setw(25) << pmu_info.size << " |\n";
    // Print the rest of the members with appropriate setw values
    out << "| " << std::setw(16) << "pmu:" << std::setw(25) << pmu_info.pmu << " |\n";
    out << "| " << std::setw(16) << "type:" << std::setw(25) << pmu_info.type << " |\n";
    out << "| " << std::setw(16) << "nevents:" << std::setw(25) << pmu_info.nevents << " |\n";
    out << "| " << std::setw(16) << "first_event:" << std::setw(25) << pmu_info.first_event << " |\n";
    out << "| " << std::setw(16) << "max_encoding:" << std::setw(25) << pmu_info.max_encoding << " |\n";
    out << "| " << std::setw(16) << "num_cntrs:" << std::setw(25) << pmu_info.num_cntrs << " |\n";
    out << "| " << std::setw(16) << "num_fixed_cntrs:" << std::setw(25) << pmu_info.num_fixed_cntrs << " |\n";
    out << "| " << std::setw(16) << "is_present:" << std::setw(25) << pmu_info.is_present << " |\n";
    out << "| " << std::setw(16) << "is_dfl:" << std::setw(25) << pmu_info.is_dfl << " |\n";
    out << "| " << std::setw(16) << "reserved_bits:" << std::setw(25) << pmu_info.reserved_bits << " |\n";
    out << std::string(horizontalLineWidth, '-') << "\n";

    return out;
}

namespace optkit::core
{
    bool Query::is_active = false;

    void Query::init()
    {
        if (pfm_initialize() == PFM_SUCCESS)
        {
            is_active = true;
            OPTKIT_CORE_INFO("pfm initialized successfully!");
        }
        else
        {
            is_active = false;
            OPTKIT_CORE_ERROR("pfm initialize failed!");
        }
    }
    void Query::destroy()
    {
        pfm_terminate();
        is_active = false;
    }
    
    pfm_pmu_info_t Query::pmu_info(const char *pmu_name)
    {
        pfm_pmu_info_t pmu_info;
        memset(&pmu_info, 0, sizeof(pfm_pmu_info_t));

        if (OPT_LIKELY(Query::is_active))
            pfm_get_pmu_info(PFM_PMU_INTEL_ICL, &pmu_info);
        else{
            OPTKIT_CORE_WARN("pfm is NOT initialized!");
        }
        return pmu_info;
    }
    void Query::local_pmu_info()
    {
    }
    void Query::event_info(const char *pmu_event_name)
    {
    }
} // namespace optkit::core

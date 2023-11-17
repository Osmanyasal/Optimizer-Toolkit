
#include <query.hh>

namespace optkit::core
{
    bool Query::is_active = false;
    pfm_pmu_info_t Query::default_architectural_pmu;

    void Query::init()
    {
        if (pfm_initialize() == PFM_SUCCESS)
        {
            is_active = true;
            memset(&Query::default_architectural_pmu, 0, sizeof(pfm_pmu_info_t));
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

    pfm_pmu_info_t Query::pmu_info(int32_t pmu_id)
    {
        pfm_pmu_info_t pmu_info;
        memset(&pmu_info, 0, sizeof(pfm_pmu_info_t));

        if (OPT_LIKELY(Query::is_active))
        {
            pfm_get_pmu_info((pfm_pmu_t)pmu_id, &pmu_info);
        }
        else
        {
            OPTKIT_CORE_WARN("pfm is NOT initialized!");
        }
        return pmu_info;
    }

    pfm_pmu_info_t Query::default_pmu_info()
    {
        if (OPT_LIKELY(Query::default_architectural_pmu.is_dfl))
            return Query::default_architectural_pmu;

        std::vector<int32_t> pmu_ids = Query::avail_pmu_ids();
        for (auto pmu_id : pmu_ids)
        {
            pfm_pmu_info_t info = Query::pmu_info(pmu_id);
            if (info.is_dfl || info.type == PFM_PMU_TYPE_CORE)
            {
                Query::default_architectural_pmu = info;
                return Query::default_architectural_pmu;
            }
        }
        // If not found return defaul pmu_info
        OPTKIT_CORE_WARN("Default PMU architecture is not detected!");
        pfm_pmu_info_t pmu_info;
        memset(&pmu_info, 0, sizeof(pfm_pmu_info_t));
        return pmu_info;
    }

    void Query::list_avail_events(int32_t pmu_id)
    {
        if (OPT_LIKELY(Query::is_active))
        {
            pfm_event_info_t info;
            pfm_pmu_info_t pinfo;
            int32_t i, ret;

            memset(&info, 0, sizeof(info));
            memset(&pinfo, 0, sizeof(pinfo));

            info.size = sizeof(info);
            pinfo.size = sizeof(pinfo);

            ret = pfm_get_pmu_info((pfm_pmu_t)pmu_id, &pinfo);
            if (ret != PFM_SUCCESS)
            {
                OPTKIT_CORE_ERROR("Cannot get PMU info");
            }

            for (i = pinfo.first_event; i != -1; i = pfm_get_event_next(i))
            {
                ret = pfm_get_event_info(i, pfm_os_t::PFM_OS_NONE, &info);
                if (ret != PFM_SUCCESS)
                {
                    OPTKIT_CORE_ERROR("Cannot get event info");
                }
                else
                    std::cout << (pinfo.is_present ? "Active" : "Supported") << " Event: " << pinfo.name << "::" << info.name << std::endl;
            }
        }
        else
        {
            OPTKIT_CORE_WARN("pfm is NOT initialized!");
        }
    }
    pfm_event_info_t Query::event_detail(int32_t pmu_id, uint32_t event_code)
    {

        pfm_event_info_t info;
        pfm_pmu_info_t pinfo;
        int32_t i, ret;

        memset(&info, 0, sizeof(info));
        memset(&pinfo, 0, sizeof(pinfo));

        info.size = sizeof(info);
        pinfo.size = sizeof(pinfo);

        if (OPT_LIKELY(Query::is_active))
        {
            ret = pfm_get_pmu_info((pfm_pmu_t)pmu_id, &pinfo);
            if (ret != PFM_SUCCESS)
            {
                OPTKIT_CORE_ERROR("Cannot get PMU info");
            }

            for (i = pinfo.first_event; i != -1; i = pfm_get_event_next(i))
            {
                ret = pfm_get_event_info(i, pfm_os_t::PFM_OS_NONE, &info);
                if (ret != PFM_SUCCESS)
                {
                    OPTKIT_CORE_ERROR("Cannot get event info");
                }
                else
                {
                    if (info.code != event_code)
                        continue;
                    return info;
                }
            }
        }
        else
        {
            OPTKIT_CORE_WARN("pfm is NOT initialized!");
        }
        return info;
    }

    void Query::list_avail_pmus()
    {
        if (OPT_LIKELY(Query::is_active))
        {
            std::cout << "[INFO] Listing Available PMUs...." << std::endl;
            int32_t i = 0;
            pfm_for_all_pmus(i)
            {
                pfm_pmu_info_t pmu_info = Query::pmu_info(i);
                if (pmu_info.is_present)
                    std::cout << pmu_info << std::endl;
            }
        }
        else
        {
            OPTKIT_CORE_WARN("pfm is NOT initialized!");
        }
    }

    std::vector<int32_t> Query::avail_pmu_ids()
    {
        std::vector<int32_t> avail_pmu_ids;

        if (OPT_LIKELY(Query::is_active))
        {
            int32_t i = 0;
            pfm_for_all_pmus(i)
            {
                if (Query::pmu_info(i).is_present)
                    avail_pmu_ids.push_back(i);
            }
        }
        else
        {
            OPTKIT_CORE_WARN("pfm is NOT initialized!");
        }

        return avail_pmu_ids;
    }

    std::map<int32_t, std::vector<int32_t>> Query::detect_packages()
    {
        std::map<int32_t, std::vector<int32_t>> result;

        int32_t last_package_id = -1;
        int32_t core_id = 0;
        while (true)
        {
            try
            {
                std::string output = read_file("/sys/devices/system/cpu/cpu" + std::to_string(core_id) + "/topology/physical_package_id", false);
                int32_t package_id = std::stoi(output);
                if (package_id > last_package_id)
                {
                    last_package_id = package_id;
                    result[last_package_id] = {};
                }
                result[last_package_id].push_back(core_id);
                core_id++;
            }
            catch (const std::exception &e)
            {
                break; // when there's no more file/cores.
            }
        }
        return result;
    }

    int32_t Query::avail_rapl_read_methods()
    {
        int32_t result = 0;

        if (is_rapl_powercap_avail())
            result = result | (int32_t)RaplReadMethods::POWERCAP;

        if (is_rapl_perf_avail())
            result = result | (int32_t)RaplReadMethods::PERF;

        if (is_rapl_msr_avail())
            result = result | (int32_t)RaplReadMethods::MSR;

        return result;
    }

    bool Query::is_rapl_msr_avail()
    {
        OPTKIT_CORE_WARN("MSR avail check not implemented in this version!");
        return false;
    }

    bool Query::is_rapl_perf_avail()
    {
        if (is_path_exists("/sys/bus/event_source/devices/power/type"))
            return true;
        else
        {
            OPTKIT_CORE_WARN("No perf_event rapl support found (requires Linux 3.14).");
            return false;
        }
    }
    bool Query::is_rapl_powercap_avail()
    {
        if (is_path_exists("/sys/class/powercap/intel-rapl/intel-rapl:0/"))
            return true;
        else
        {
            OPTKIT_CORE_WARN("No powercap support found.");
            return false;
        }
    }

    std::vector<RaplDomainInfo> Query::rapl_domain_info()
    {
        std::vector<RaplDomainInfo> res;

        for (int32_t domain = static_cast<int>(RaplDomain::BEGIN); domain < static_cast<int>(RaplDomain::END); domain = domain << 1)
        {
            try
            {
                std::string domain_name = rapl_domain_name_mapping.at(domain);
                std::string config = read_file("/sys/bus/event_source/devices/power/events/" + domain_name);
                std::string scale = read_file("/sys/bus/event_source/devices/power/events/" + domain_name + ".scale");
                std::string units = read_file("/sys/bus/event_source/devices/power/events/" + domain_name + ".unit");

                config.erase(std::remove(config.begin(), config.end(), '\n'), config.end());
                scale.erase(std::remove(scale.begin(), scale.end(), '\n'), scale.end());
                units.erase(std::remove(units.begin(), units.end(), '\n'), units.end());

                config = config.substr(config.find("=") + 1);
                std::stringstream ss;
                ss << std::hex << config;
                uint64_t l_conf;
                ss >> l_conf;

                res.push_back({(RaplDomain)domain, domain_name, l_conf, std::stod(scale), units});
            }
            catch (const std::exception &e)
            {
                // OPTKIT_CORE_ERROR("{}", e.what());
            }
        }

        return res;
    }

} // namespace optkit::core

std::ostream &operator<<(std::ostream &out, const std::map<int32_t, std::vector<int32_t>> &packages)
{
    std::ostringstream oss;
    int32_t total_cores = 0;
    int32_t count = 0;
    for (const auto &entry : packages)
    {
        int32_t package_id = entry.first;
        const std::vector<int32_t> &core_ids = entry.second;
        total_cores += core_ids.size();

        for (int32_t core_id : core_ids)
        {
            oss << core_id << " (" << package_id << ") ";
            if (++count % 8 == 0)
                oss << std::endl;
        }
    }
    OPTKIT_CORE_INFO("\n\tDetected {} cores in {} packages\n---------------------------------------\n{}", total_cores, packages.size(), oss.str());
    return out;
}

std::ostream &operator<<(std::ostream &out, const pfm_event_info_t &event_info)
{
    if (OPT_UNLIKELY(event_info.idx == 0))
        return out;

    // Calculate the number of spaces needed for "Information" label and vertical bars
    int32_t _10_plus_event_info_desc_size = 10 + std::string(event_info.desc).size();
    int32_t horizontalLineWidth = 16 + _10_plus_event_info_desc_size + 4; // Width of the horizontal line 4 for (| and blank) x 2
    int32_t informationWidth = horizontalLineWidth - 2;                   // 2 is for the two vertical bars
    int32_t paddingWidth = (informationWidth - 22) / 2;                   // 16 is for the "PMU Event Information" label

    // Output the top horizontal line
    out << std::string(horizontalLineWidth, '-') << "\n";

    out << "| ";

    // Print padding before "Information" label
    out << std::setw(paddingWidth) << " ";
    out << "PMU Event Information";

    // Print padding after "Information" label
    out << std::setw(paddingWidth) << " ";

    out << "|\n";

    // Output the middle horizontal line
    out << std::string(horizontalLineWidth, '-') << "\n";

    out << "| " << std::setw(16) << "name:" << std::setw(_10_plus_event_info_desc_size) << event_info.name << " |\n";
    out << "| " << std::setw(16) << "desc:" << std::setw(_10_plus_event_info_desc_size) << event_info.desc << " |\n";
    out << "| " << std::setw(16) << "size:" << std::setw(_10_plus_event_info_desc_size) << event_info.size << " |\n";
    out << "| " << std::setw(16) << "code:" << std::setw(_10_plus_event_info_desc_size) << event_info.code << " |\n";
    // Print the rest of the members with appropriate setw values
    out << "| " << std::setw(16) << "pmu:" << std::setw(_10_plus_event_info_desc_size - 6) << optkit::core::pmu_names[(std::size_t)event_info.pmu] << std::setw(6) << "(" + std::to_string(event_info.pmu) + ")"
        << " |\n";
    out << "| " << std::setw(16) << "dtype:" << std::setw(_10_plus_event_info_desc_size - 6) << optkit::core::pmu_types[(std::size_t)event_info.dtype] << std::setw(6) << "(" + std::to_string(event_info.pmu) + ")"
        << " |\n";

    out << "| " << std::setw(16) << "idx:" << std::setw(_10_plus_event_info_desc_size) << event_info.idx << " |\n";
    out << "| " << std::setw(16) << "nattrs:" << std::setw(_10_plus_event_info_desc_size) << event_info.nattrs << " |\n";
    out << "| " << std::setw(16) << "reserved:" << std::setw(_10_plus_event_info_desc_size) << event_info.reserved << " |\n";
    out << "| " << std::setw(16) << "is_precise:" << std::setw(_10_plus_event_info_desc_size) << event_info.is_precise << " |\n";
    out << "| " << std::setw(16) << "is_speculative:" << std::setw(_10_plus_event_info_desc_size) << event_info.is_speculative << " |\n";
    out << "| " << std::setw(16) << "support_hw_smpl:" << std::setw(_10_plus_event_info_desc_size) << event_info.support_hw_smpl << " |\n";
    out << "| " << std::setw(16) << "reserved_bits:" << std::setw(_10_plus_event_info_desc_size) << event_info.reserved_bits << " |\n";
    out << std::string(horizontalLineWidth, '-') << "\n";

    return out;
}

std::ostream &operator<<(std::ostream &out, const pfm_pmu_info_t &pmu_info)
{

    // Calculate the number of spaces needed for "Information" label and vertical bars
    int32_t horizontalLineWidth = 16 + 30 + 4;          // Width of the horizontal line 4 for (| and blank) x 2
    int32_t informationWidth = horizontalLineWidth - 2; // 2 is for the two vertical bars
    int32_t paddingWidth = (informationWidth - 16) / 2; // 16 is for the "PMU Information" label

    // Output the top horizontal line
    out << std::string(horizontalLineWidth, '-') << "\n";

    out << "| ";

    // Print padding before "Information" label
    out << std::setw(paddingWidth) << " ";
    out << "PMU Information";

    // Print padding after "Information" label
    out << std::setw(paddingWidth) << " ";

    out << "|\n";

    // Output the middle horizontal line
    out << std::string(horizontalLineWidth, '-') << "\n";

    out << "| " << std::setw(16) << "name:" << std::setw(30) << pmu_info.name << " |\n";
    out << "| " << std::setw(16) << "desc:" << std::setw(30) << pmu_info.desc << " |\n";
    out << "| " << std::setw(16) << "size:" << std::setw(30) << pmu_info.size << " |\n";
    // Print the rest of the members with appropriate setw values
    out << "| " << std::setw(16) << "pmu:" << std::setw(24) << optkit::core::pmu_names[(std::size_t)pmu_info.pmu] << std::setw(6) << "(" + std::to_string(pmu_info.pmu) + ")"
        << " |\n";
    out << "| " << std::setw(16) << "type:" << std::setw(24) << optkit::core::pmu_types[(std::size_t)pmu_info.type] << std::setw(6) << "(" + std::to_string(pmu_info.pmu) + ")"
        << " |\n";
    out << "| " << std::setw(16) << "nevents:" << std::setw(30) << pmu_info.nevents << " |\n";
    out << "| " << std::setw(16) << "first_event:" << std::setw(30) << pmu_info.first_event << " |\n";
    out << "| " << std::setw(16) << "max_encoding:" << std::setw(30) << pmu_info.max_encoding << " |\n";
    out << "| " << std::setw(16) << "num_cntrs:" << std::setw(30) << pmu_info.num_cntrs << " |\n";
    out << "| " << std::setw(16) << "num_fixed_cntrs:" << std::setw(30) << pmu_info.num_fixed_cntrs << " |\n";
    out << "| " << std::setw(16) << "is_present:" << std::setw(30) << pmu_info.is_present << " |\n";
    out << "| " << std::setw(16) << "is_dfl:" << std::setw(30) << pmu_info.is_dfl << " |\n";
    out << "| " << std::setw(16) << "reserved_bits:" << std::setw(30) << pmu_info.reserved_bits << " |\n";
    out << std::string(horizontalLineWidth, '-') << "\n";

    return out;
}
#include <iostream>
#include <optkit.hh>

void print_pmu();
void print_rapl();
void print_cpu();

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{false};
    print_cpu();
    print_rapl();
    print_pmu();
    return 0;
}

void print_pmu()
{
    std::cout << "============== Default PMU ==============\n\n";
    std::cout << QueryPMU::default_pmu_info();

    std::cout << "\n";
    std::cout << "============== Avail PMUs ==============\n\n";

    QueryPMU::list_avail_pmus();

    std::cout << "\n";
    std::cout << "============== Avail PMU Events ==============\n\n";
    for (int i : QueryPMU::avail_pmu_ids())
    {
        QueryPMU::list_avail_events(i);
        std::cout << "\n------------------------\n";
    }
    std::cout << std::endl;
}
void print_rapl()
{

    std::cout << "============== Rapl Domain Info ==============\n\n";
    for (auto &item : QueryRapl::rapl_domain_info())
        std::cout << item << std::endl;

    std::cout << "\n";
    std::cout << "============== Rapl Read Methods ==============\n\n";
    std::cout << "RAPL PERF read avail: [" << QueryRapl::is_rapl_perf_avail() << "]\n";
    std::cout << "RAPL powercap read avail: [" << QueryRapl::is_rapl_powercap_avail() << "]\n";
    std::cout << "RAPL MSR read avail: [" << QueryRapl::is_rapl_msr_avail() << "]\n";
    std::cout << std::endl;
}
void print_cpu()
{

    std::cout << "============== Detect Packages ==============\n";
    std::cout << Query::detect_packages() << std::endl;
    std::cout << "TOTAL # OF SOCKETS: " << Query::num_sockets << "\n";
    std::cout << "TOTAL # OF CORES: " << Query::num_cores << "\n";

    for (int socket = 0; socket < Query::num_sockets; socket++)
    {
        std::cout << "Socket[" << socket << "] Core Avail Freq(HZ): ";
        const auto &freq_list = QueryFreq::get_scaling_available_frequencies(Query::detect_packages().at(socket)[0]);
        for (auto iter = freq_list.rbegin(); iter != freq_list.rend(); iter++)
            std::cout << *iter << " ";
        std::cout << "\n";
        
        std::cout << "Socket[" << socket << "] Uncore Limits Min-Max(HZ): " << CPUFrequency::get_uncore_min_max(socket) << "\n";
        std::cout << "Socket[" << socket << "] Current Uncore Freq(HZ): " << CPUFrequency::get_uncore_frequency(socket) << "\n";

        std::cout << std::endl;
    }

    for (int i = 0; i < Query::num_cores; i++)
    {
        std::cout << "CPU(" + std::to_string(i) + ") BIOS LIMIT: " << QueryFreq::get_bios_limit(i) << "\n";
        std::cout << "CPU(" + std::to_string(i) + ") MIN CORE FREQ(HZ): " << QueryFreq::get_cpuinfo_min_freq(i) << "\n";
        std::cout << "CPU(" + std::to_string(i) + ") MAX CORE FREQ(HZ): " << QueryFreq::get_cpuinfo_max_freq(i) << "\n";
        std::cout << "CPU(" + std::to_string(i) + ") CURRENT MIN CORE FREQ(HZ): " << QueryFreq::get_scaling_min_limit(i) << "\n";
        std::cout << "CPU(" + std::to_string(i) + ") CURRENT MAX CORE FREQ(HZ): " << QueryFreq::get_scaling_max_limit(i) << "\n";
        std::cout << "CPU(" + std::to_string(i) + ") SCALING DRIVER: " << QueryFreq::get_scaling_driver(i);
        std::cout << "CPU(" + std::to_string(i) + ") AVAIL CORE FREQ(HZ): ";
        const auto &freq_list = QueryFreq::get_scaling_available_frequencies(i);
        for (auto iter = freq_list.rbegin(); iter != freq_list.rend(); iter++)
            std::cout << *iter << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

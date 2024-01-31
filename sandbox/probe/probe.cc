#include <iostream>
#include <optkit.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{false};

    std::cout << "============== Detect Packages ==============\n";
    std::cout << Query::detect_packages() << std::endl;
    
    std::cout << "\n";
    std::cout << "============== Rapl Domain Info ==============\n\n";
    for (auto &item : Query::rapl_domain_info())
        std::cout << item << std::endl;

    std::cout << "\n";
    std::cout << "============== Rapl Read Methods ==============\n\n";
    std::cout << "RAPL PERF read avail: [" << Query::is_rapl_perf_avail() << "]\n";
    std::cout << "RAPL powercap read avail: [" << Query::is_rapl_powercap_avail() << "]\n";
    std::cout << "RAPL MSR read avail: [" << Query::is_rapl_msr_avail() << "]\n";

    std::cout << "\n";
    std::cout << "============== Default PMU ==============\n\n";
    std::cout << Query::default_pmu_info();

    std::cout << "\n";
    std::cout << "============== Avail PMUs ==============\n\n";
    Query::list_avail_pmus();
 
    // std::cout << "\n";
    // std::cout << "============== Avail PMU Events ==============\n\n";
    // for(int i : Query::avail_pmu_ids()){
    //     Query::list_avail_events(i);
    //     std::cout << "\n------------------------\n";
    // }

    return 0;
}
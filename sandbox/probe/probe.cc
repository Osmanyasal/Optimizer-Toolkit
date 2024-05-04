#include <iostream>
#include <optkit.hh>

void print_pmu();
void print_rapl();
void print_cpu();

int32_t main(int32_t argc, char **argv)
{

    if (argc < 2)
    {
        OptimizerKit optkit{false};
        print_cpu();
        print_rapl();
        print_pmu();
    }
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
    std::cout << "\n";
}
void print_cpu()
{

    std::cout << "============== Detect Packages ==============\n";
    std::cout << Query::detect_packages() << std::endl;
    std::cout << "\n";
}

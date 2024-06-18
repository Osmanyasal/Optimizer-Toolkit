#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__MSR_UTILS__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__MSR_UTILS__HH

#include <sys/types.h>
#include <cstdint>
#include <stdio.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <utils.hh>

namespace optkit::core::freq
{

    OPT_FORCE_INLINE void read_msr(int cpuid, off_t MSR_REGISTER_address, uint64_t *MSR_REGISTER_bits)
    {
        EXEC_IF_ROOT;
        char msr_file_name[64];
        sprintf(msr_file_name, "/dev/cpu/%d/msr_safe", cpuid);
        int fd = open(msr_file_name, O_RDONLY);
        if (fd < 0)
        {
            OPTKIT_CORE_WARN("read msr error [{}]", cpuid);
            return;
        }

        if (pread(fd, MSR_REGISTER_bits, sizeof MSR_REGISTER_bits, MSR_REGISTER_address) != sizeof MSR_REGISTER_bits)
        {

            OPTKIT_CORE_WARN("read msr error -- cannot read register {}",MSR_REGISTER_address);
        }
        close(fd);
    }

    OPT_FORCE_INLINE static void write_msr(int cpuid, off_t MSR_REGISTER_address, uint64_t MSR_REGISTER_bits)
    {
        EXEC_IF_ROOT;
        char msr_file_name[64];
        sprintf(msr_file_name, "/dev/cpu/%d/msr_safe", cpuid);
        int fd = open(msr_file_name, O_WRONLY);
        if (fd < 0)
        {
            OPTKIT_CORE_WARN("write msr error [{}]", cpuid);
            return;
        }

        if (pwrite(fd, &MSR_REGISTER_bits, sizeof MSR_REGISTER_bits, MSR_REGISTER_address) != sizeof MSR_REGISTER_bits)
        {
            OPTKIT_CORE_WARN("read msr error -- cannot read register {}", MSR_REGISTER_address);
        }
    }

}

#endif

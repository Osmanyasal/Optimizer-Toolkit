---@diagnostic disable: undefined-global

print("Current platform: " .. os.target())
-- Check if the platform is Linux
if os.target() ~= "linux" then
    print("❌ This script is only supported on Linux platforms.")
    os.exit(1)  -- Exit with a non-zero status to terminate the script
end


LIB_MSR_SAFE_PATH = './lib/msr-safe'
LIB_SPD_PATH = './lib/spdlog'
LIB_PFM_PATH = './lib/libpfm'
CORE_EVENTS_DIR = './core/events'
UTILS_DIR = './utils'
LIB_X86_ADAPT_PATH = './lib/x86-adapt'

workspace "OptimizerToolkit"
    configurations { "Debug", "Release" }
    architecture "x64"

project "OptimizerToolkit"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++11"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin/obj/%{cfg.buildcfg}"

    includedirs {
        "."
    }

    files {
        "./src/**.cc",
        "./src/**.hh"
    }

    -- Linking dynamic libraries for Intel systems
    linkoptions { "-fopenmp", "-lpfm" }
    links { "pthread", "dl", "tensorflow", "spdlog" }

    -- Compiler options
    filter "configurations:Debug"
        symbols "On"
        defines { "OPTKIT_MODE_DEBUG" }
        buildoptions { "-Wall", "-O0", "-g", "-fopenmp", "-msse", "-march=native", "-mavx2" } 

    filter "configurations:Release"
        optimize "On"
        symbols "Off"
        defines { "OPTKIT_MODE_NDEBUG" }
        buildoptions { "-Wall", "-O2", "-fopenmp", "-msse", "-march=native", "-mavx2" }
 
    filter{}    -- stop filtering, below is globally accessible

   
    prebuildcommands {
        -- Use global variables in the prebuildcommands
        "if [ ! -f " .. LIB_MSR_SAFE_PATH .. "/all_set ]; then \\",
        "    cd " .. LIB_MSR_SAFE_PATH .. " && make && make install && \\",
        "    sudo insmod ./msr-safe.ko && sudo chmod g+rw /dev/cpu/*/msr_safe /dev/cpu/msr_* && \\",
        "    sudo chgrp $(whoami) /dev/cpu/*/msr_safe /dev/cpu/msr_batch /dev/cpu/msr_safe_version && \\",
        "    sudo chgrp $(whoami) /dev/cpu/msr_allowlist && \\",
        "    echo \"0x00000620 0xFFFFFFFFFFFFFFFF\" > /dev/cpu/msr_allowlist && \\",
        "    touch all_set; \\",
        "fi",

        "if [ ! -f " .. LIB_SPD_PATH .. "/build/libspdlog.a ]; then \\",
        "    cd " .. LIB_SPD_PATH .. " && ./install.sh; \\",
        "fi",

        "if [ ! -f " .. LIB_PFM_PATH .. "/all_set ]; then \\",
        "    cd " .. LIB_PFM_PATH .. " && ./install.sh; \\",
        "fi",

        "if [ ! -f " .. CORE_EVENTS_DIR .. "/all_set ]; then \\",
        "    echo \"⛏️ Exporting events from libpfm4\" && \\",
        "    cd " .. UTILS_DIR .. " && python3 pmu_parser.py $(find " .. LIB_PFM_PATH .. "/lib/events -type f \\( -name \"intel*.h\" -or -name \"amd*.h\" -or -name \"arm*.h\" -or -name \"power*.h\" \\) -exec echo \"../../{}\" \\;); \\",
        "    touch " .. CORE_EVENTS_DIR .. "/all_set; \\",
        "fi",

        "if [ ! -f " .. LIB_X86_ADAPT_PATH .. "/all_set ]; then \\",
        "    echo \"⛏️ Building x86 adapt library\" && \\",
        "    cd " .. LIB_X86_ADAPT_PATH .. " && ./install.sh; \\",
        "fi"
    }

    local actions = {
        clean = "clean",
        install = "install",
        remove = "remove",
        gen_doc = "gen-doc",
        remove_doc = "remove-doc"
    }

    -- Tasks for clean, install, and generate docs
    newaction {
        trigger = actions.clean,
        description = "clean bin and build directory",
        execute = function()
            os.rmdir("./bin")
            os.rmdir("./build")
            print("🧹 Cleaned build directories!")
        end
    }

    newaction {
        trigger = actions.install,
        description = "Install headers and libraries to system directories",
        execute = function()
            os.execute("sudo mkdir -p /usr/local/include/optkit")   -- create optkit directory for headers
            os.execute("cd src; sudo find ./ -type f -name \"*.hh\" -exec cp --parents {} \"/usr/local/include/optkit/\" \\;") -- copy all header files by keeping the file structure as-is
            os.execute("sudo cp -R ./bin/liboptkit.a /usr/local/lib") -- copy static library 
            os.execute("sudo cp -R ./bin/liboptkit.so /usr/local/lib") -- copy dynamic library 
            print("✅ Installed headers and libraries!")
        end
    }

    newaction {
        trigger = actions.remove,
        description = "Remove OPTKIT from the system. (deletes all OPTKIT-cli and libraries from the system)",
        execute = function()
            os.execute("rm -rf /usr/local/include/optkit")  -- removes optkit headers
            os.execute("rm -f /usr/local/bin/optkit*")      -- removes optkit binaries
            os.execute("rm -f /usr/local/lib/liboptkit.a")  -- removes optkit library
            print("🧹 OPTKIT removed from the system")
        end
    }

    newaction {
        trigger = actions.gen_doc,
        description = "Generate documentation",
        execute = function()
            os.execute("doxygen ./doxyfile")    -- create doxygen file
            print("📄 Documentation generated!")
        end
    }

    newaction {
        trigger = actions.remove_doc,
        description = "Remove documentation",
        execute = function()
            os.execute("rm -rf ./doc")    -- create doxygen file
            print("📄 Documentation Removed!")
        end
    }

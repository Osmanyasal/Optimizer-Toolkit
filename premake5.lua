---@diagnostic disable: undefined-global
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
        "./src/**.cc"
    }

    -- Compiler options
    filter "configurations:Debug"
        symbols "On"
        defines { "DEBUG" }
        buildoptions { "-Wall", "-O0", "-g", "-fopenmp", "-msse", "-march=native", "-mavx2" }
        linkoptions { "-fopenmp", "-lpfm" }

    filter "configurations:Release"
        optimize "On"
        defines { "NDEBUG" }
        buildoptions { "-Wall", "-O2", "-fopenmp", "-msse", "-march=native", "-mavx2" }
        linkoptions { "-fopenmp", "-lpfm" }

    -- Linking dynamic libraries for Intel systems
    filter "system:linux"
        links { "pthread", "dl", "tensorflow", "spdlog" }

    -- Output executable and library
    postbuildcommands {
        "{COPY} %{cfg.buildtarget.abspath} ../bin/%{cfg.buildcfg}/optimizer_toolkit.core"
    }

-- Tasks for clean, install, and generate docs
newaction {
    trigger = "clean",
    description = "Clean the build files",
    execute = function()
        os.rmdir("./bin")
        print("🧹 Cleaned build directories!")
    end
}

newaction {
    trigger = "install",
    description = "Install headers and libraries to system directories",
    execute = function()
        os.execute("sudo mkdir -p /usr/local/include/optkit")
        os.execute("sudo find ./src/ -type f -name \"*.hh\" -exec cp {} \"/usr/local/include/optkit/\" \\;")
        os.execute("sudo cp -R ./bin/liboptkit.a /usr/local/lib")
        print("✅ Installed headers and libraries!")
    end
}

newaction {
    trigger = "doc",
    description = "Generate documentation",
    execute = function()
        os.execute("doxygen ./doxyfile")
        print("📄 Documentation generated!")
    end
}

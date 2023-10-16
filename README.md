<div id="user-content-toc" align=center>
  <ul>
    <summary><h1 style="display: inline-block;">Samaritan</h1></summary>
  </ul>
</div>
<div align="center">
            <img align="center" alt="ICON" width="500" height="500" src="https://github.com/Osmanyasal/Samaritan/assets/22853419/724adbf8-853b-4d73-8bc6-81d184887526" /> 
</div>  
<div align="center">
                <img align="center" title="C++" alt="C++" width="80px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/f79dfb8b-ec5e-43a9-b3ec-7db4555b54e0" />
                &nbsp;&nbsp; 
                <img align="center" title="Linux" alt="Linux" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/e67369bc-582f-4d90-bd92-7765b6f2a357" /> 
                &nbsp;&nbsp;
                <img align="center" title="Mac" alt="Mac" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/a635c69d-cc34-46df-a0ed-de5771609a4d" />
                &nbsp;&nbsp;
                <!-- <img align="center" alt="Windows" width="60px" src="https://github.com/Osmanyasal/Recursion-Engine/assets/22853419/c1717d00-63d2-426f-a648-18a2d618f849" /> -->
</div>
<div align="center">
                <img align="center" title="GLFW" alt="GLFW" width="60px" src="https://www.glfw.org/img/favicon/favicon-196x196.png" />
                &nbsp;&nbsp; 
                <img align="center" title="libpfm4" alt="libpfm4" width="100px" src="https://github.com/Osmanyasal/Samaritan/assets/22853419/5b4313af-b87e-4615-b110-75733b67289d" /> 
                &nbsp;&nbsp; 
                <img align="center" title="Dear Imgui" alt="Dear Imgui" width="60px" src="https://raw.githubusercontent.com/wiki/sammyfreg/netImgui/Web/img/DearImGui.png" /> 
                &nbsp;&nbsp; 
                <img align="center" title="Doxygen" alt="Doxygen" width="150px" src="https://www.doxygen.nl/images/doxygen.png" /> 
</div>

## About <br>
* Cross Platform Performance Ecosystem mainly developed for Linux and MacOS environments.<br>
* <b>Utilizes</b> all advantageous features of <b>PAPI,Linux Perf, Intel Vtune/Advisor, AMD uProf profilers into a single, unified platform</b> by harnessing the code and binary instrumentation techniques while providing a straightforward but elegant GUI for advanced in- and post-development monitoring.
* <b>100% CPU agnostic profiling</b>
* Provides <b>100% accuracy</b> thanks to code-line instrumentation.
* <b>An Intuitive Programming API for in-development monitoring support</b>
* Supports diverse PMU monitoring with <b>0 learning curve</b>.
* <b>Bottleneck detection in any phase of the development.</b>
* <b>Overhead is very very low</b> and upto the programmer itself.
* Python binding. Yes you’ll have a full python support in code-line instrumentation.
* Developed with C++ and Make/Bash scripts.
* <b>You can monitor any executable file</b>
* <b>Use in your c++ and python projects</b>

## To run 🚀 <br>
```
git clone --recurse-submodules https://github.com/Osmanyasal/Samaritan.git
cd ./Samaritan
make
```

## PERFORMANCE AID 🔎<br>
 
## PERFORMANCE MONITORING 🔎<br>
The engine itself contains many profiling tools ```(Perf, Valgrind, Intel Vtune, Advisor...)``` and binary instrumentations ```(chrome://tracing)``` allowing the user to write high-performant code and monitor and optimize the pre-written code.
You can use the following makefile targets to collect meaningful metrics <br>
All targets use perf tool and Valgrind, so make sure they're installed<br>
```
make tma_analiysis # makes tma analysis unearths how much of your application {front,back}-end bounded or bad-speculated 
make monitor_callstack # hottest ran functions 
make mem_check # runs the Valgrind tool to make a detailed memory analysis.
```
## Currently
 - You can follow the current development status at projects section
 - Main support is on Linux, MacOS and Windows side-supported.
 - Developing fundamentals; OpenGL and glfw3 are preferred, Vulkan and DirectX will be supported later.
 

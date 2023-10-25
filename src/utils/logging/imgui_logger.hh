#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__UTILS__LOGGING__IMGUI_LOGGER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__UTILS__LOGGING__IMGUI_LOGGER_HH

#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class ImGuiLogger
{
private:
    ImGuiLogger() = delete;
    ~ImGuiLogger() = delete;

public:
    static void Clear() { Buf.clear(); }
    static void AddLog(const char *fmt, ...) IM_FMTARGS(1);
    static void Draw();

private:
    static ImGuiTextBuffer Buf;
    static ImGuiTextFilter Filter;
    static ImVector<int32_t> LineOffsets; // Index to lines offset
    static bool ScrollToBottom;
};

#endif
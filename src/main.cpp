// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
#include <stdio.h>
#include <unistd.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include<emscripten/emscripten.h>
#include <iostream>
#include "render_host.h"
#include "editor.h"

// Our state
extern ImVec4 clear_color;
extern GLFWwindow* window;

extern int display_w;
extern int display_h;
extern "C" void EMSCRIPTEN_KEEPALIVE native_resize(int width, int height) {
    display_w = width;
    display_h = height;
    glfwSetWindowSize(window, display_w, display_h);
}

void setup_dockspace() {
    // Set the parent window's position, size, and viewport to match that of the main viewport. This is so the parent window
    // completely covers the main viewport, giving it a "full-screen" feel.
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    // Set the parent window's styles to match that of the main viewport:
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f); // No corner rounding on the window
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f); // No border around the window

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;

    // Manipulate the window flags to make it inaccessible to the user (no titlebar, resize/move, or navigation)
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

    bool open = true;
    ImGui::Begin("Workspace##", &open, window_flags);

    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if(ImGui::MenuItem("Open")) {
                render_host::queue_obj(new editor("/test.txt", "Text Editor"));
            }
            ImGui::MenuItem("Save (Download)");

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
}
void end_dockspace() {
    ImGui::PopStyleVar(2);
    ImGui::End();
}

void do_frame()
{   
    // Poll and handle events (inputs, window resize, etc.)
    // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
    // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
    // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
    // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
    glfwPollEvents();

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    setup_dockspace();

    render_host::render_all();

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;

    //ImGui::SetNextWindowSize(ImVec2(400, 400));

    ImGui::Begin("Explorer", nullptr, window_flags);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File Menu")) {
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::End();

    end_dockspace();

    // Rendering
    ImGui::Render();
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
}

extern void setup_glfw();
extern void setup_imgui();

int main(int, char**)
{
    setup_glfw();
    setup_imgui();
    
    // Main loop
    emscripten_set_main_loop(do_frame, 0, 1);

    return 0;
}
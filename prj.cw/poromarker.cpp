﻿#include <iostream>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include<imgui_impl_opengl3_loader.h>
#include<imgui_internal.h>
#include<imgui_stdlib.h>
#include<GLFW/glfw3.h>
#include<GLFW/glfw3native.h>
#include<opencv2/opencv.hpp>


static void glfw_error_callback(int error, const char* description){
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(){

    bool show_start_window = true;
    bool show_project_window = false;

    // Test
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);         
#endif


    GLFWwindow* window = glfwCreateWindow(1280, 720, "PoroMarker", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Our state
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    cv::Mat image1 = cv::imread("C:/Users/ASUS/Downloads/poro_marker_logo(1).png", cv::IMREAD_COLOR);
    cv::Mat image;
    cv::cvtColor(image1, image, cv::COLOR_BGR2RGB);
    //create textures
    GLuint imageTexture;
    glGenTextures(1, &imageTexture);
    glBindTexture(GL_TEXTURE_2D, imageTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 0x1907, image.size().width, image.size().height, 0, 0x1907, GL_UNSIGNED_BYTE, image.data);

    // Main loop
    while (!glfwWindowShouldClose(window)){
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        if (show_start_window)// StartMenu
        {
            ImVec2 size(200, 338);
            ImGui::SetNextWindowSize(size, ImGuiCond_Once);
            ImGui::SetNextWindowPos(ImVec2((ImGui::GetIO().DisplaySize.x - size.x) * 0.5f, (ImGui::GetIO().DisplaySize.y - size.y) * 0.5f));
            ImGui::Begin("Welcome to PoroMarker",nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
            ImGui::Text("Choose an option.");
            ImGui::NewLine();
            if (ImGui::Button("Create project")){
                // Обработка нажатия кнопки "Create project"
                show_start_window = false;
                show_project_window = true;
            }
            if (ImGui::Button("Open project")){
                // Обработка нажатия кнопки "Open project"
            }
            if (ImGui::Button("Help")){
                // Обработка нажатия кнопки "Help"
            }
            // demo opencv pic
            ImGui::Image((void*)(intptr_t)imageTexture, ImVec2(image.size().width, image.size().height));

            ImGui::End();
        }
        
        if (show_project_window) {
            ImVec2 size(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y-18);
            ImGui::SetNextWindowSize(size, ImGuiCond_Once);
            ImGui::SetNextWindowPos(ImVec2((ImGui::GetIO().DisplaySize.x - size.x) * 0.5f, (ImGui::GetIO().DisplaySize.y - size.y)));
            ImGui::Begin("Project", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Open")) {
                        // Обработка команды "Open"
                    }
                    if (ImGui::MenuItem("Save")) {
                        show_start_window = true;
                        show_project_window = false;
                    }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Help")) {
                    if (ImGui::MenuItem("Docs")) {
                        // Обработка команды "Документация"
                    }
                    if (ImGui::MenuItem("About us")) {
                        // Обработка команды "О нас"
                    }
                    ImGui::EndMenu();
                }

                ImGui::EndMainMenuBar();
            }
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}
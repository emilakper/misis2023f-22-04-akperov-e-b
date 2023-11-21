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
#include<imfilebrowser/imfilebrowser.h>
#include <vector>


static void glfw_error_callback(int error, const char* description){
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

GLuint convertMatToTexture(const cv::Mat& image) {
    cv::Mat imageRGB;
    cv::cvtColor(image, imageRGB, cv::COLOR_BGR2RGB);
    GLuint imageTexture;
    glGenTextures(1, &imageTexture);
    glBindTexture(GL_TEXTURE_2D, imageTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 0x1907, imageRGB.size().width, imageRGB.size().height, 0, 0x1907, GL_UNSIGNED_BYTE, imageRGB.data);
    return imageTexture;
}

int main(){
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

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "PoroMarker", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool show_start_window = true;
    bool show_project_window = false;
    ImGui::FileBrowser dirDialog(ImGuiFileBrowserFlags_SelectDirectory | ImGuiFileBrowserFlags_MultipleSelection | ImGuiFileBrowserFlags_MultipleSelection | ImGuiFileBrowserFlags_CloseOnEsc);
    dirDialog.SetTitle("Choose folder");
    ImGui::FileBrowser fileDialog(ImGuiFileBrowserFlags_MultipleSelection | ImGuiFileBrowserFlags_CloseOnEsc);
    fileDialog.SetTitle("Choose files");
    fileDialog.SetTypeFilters({ ".png",".tif" });
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    cv::Mat image = cv::imread("C:/Users/ASUS/Downloads/poro_marker_logo(1).png", cv::IMREAD_COLOR);
    GLuint imageTexture = convertMatToTexture(image);

    int layerNumber = 0;
    int lastLayerNumber = 0;
    // Temorary Solution For testing functions, cv::Mat of layers would be given by teammate 
    std::vector<cv::Mat> layerImages;
    layerImages.push_back(cv::imread("C:/Users/ASUS/Downloads/pics/0.png", cv::IMREAD_COLOR));
    layerImages.push_back(cv::imread("C:/Users/ASUS/Downloads/pics/1.png", cv::IMREAD_COLOR));
    layerImages.push_back(cv::imread("C:/Users/ASUS/Downloads/pics/2.png", cv::IMREAD_COLOR));
    layerImages.push_back(cv::imread("C:/Users/ASUS/Downloads/pics/3.png", cv::IMREAD_COLOR));
    auto itr = layerImages.begin();
    int itrEnd = layerImages.size()-1;
    GLuint imageLayerTexture = convertMatToTexture(*itr);
    // Main loop
    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        if (show_start_window)// StartMenu
        {
            ImVec2 size(200, 334);
            ImGui::SetNextWindowSize(size, ImGuiCond_Once);
            ImGui::SetNextWindowPos(ImVec2((ImGui::GetIO().DisplaySize.x - size.x) * 0.5f, (ImGui::GetIO().DisplaySize.y - size.y) * 0.5f));
            ImGui::Begin("Welcome to PoroMarker",nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

            ImGui::SetWindowFontScale(1.0f*(ImGui::GetIO().DisplaySize.y / 1080));

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
            ImGui::Image((void*)(intptr_t)imageTexture, ImVec2(image.size().width, image.size().height));
            ImGui::End();
        }
        
        if (show_project_window) {
            ImVec2 size(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y);
            ImGui::SetNextWindowSize(size, ImGuiCond_Once);
            ImGui::SetNextWindowPos(ImVec2((ImGui::GetIO().DisplaySize.x - size.x) * 0.5f, (ImGui::GetIO().DisplaySize.y - size.y)));
            ImGui::Begin("Project", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse 
                                            | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar);

            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Open folder")) {
                        dirDialog.Open();
                    }
                    if (ImGui::MenuItem("Open files")) {
                        fileDialog.Open();
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

                // Полоска с кнопками
                ImGui::Separator();

                if (ImGui::Button("Scissors", ImVec2(80, 0))) {
                    // Обработка нажатия кнопки "Ножницы"
                }
                ImGui::SameLine();

                if (ImGui::Button("Rectangle", ImVec2(80, 0))) {
                    // Обработка нажатия кнопки "Прямоугольник"
                }

                if (ImGui::Button("Erase", ImVec2(80, 0))) {
                    // Обработка нажатия кнопки "Удаление"
                }

                if (ImGui::Button("PolyLine", ImVec2(80, 0))) {
                    // Обработка нажатия кнопки "Полилиния"
                }
                ImGui::EndMenuBar();
            }

            ImGui::SetCursorPos(ImVec2(150,25));
            ImGui::Image((void*)(intptr_t)imageLayerTexture, ImVec2(975, 975));
            ImGui::SliderInt("Layer number", &layerNumber, 0, itrEnd,"");
            ImGui::SetNextItemWidth(100);
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 600.0f);
            ImGui::InputInt(" ", &layerNumber);
            if (layerNumber < 0) {
                layerNumber = 0;
            }
            else if (layerNumber > itrEnd) {
                layerNumber = itrEnd;
            }
            if (layerNumber != lastLayerNumber) {
                lastLayerNumber = layerNumber;
                glDeleteTextures(1, &imageLayerTexture);
                imageLayerTexture = convertMatToTexture(*(itr+layerNumber));
            }
            ImGui::End();
        }
        
        dirDialog.Display();
        if (dirDialog.HasSelected())
        {
            std::vector<std::filesystem::path> selectedFiles = dirDialog.GetMultiSelected();

            for (const auto& path : selectedFiles) {
                std::cout << "Selected filename: " << path.string() << std::endl;
            }
            dirDialog.ClearSelected();
        }
        fileDialog.Display();
        if (fileDialog.HasSelected())
        {
            std::vector<std::filesystem::path> selectedFiles = fileDialog.GetMultiSelected();

            for (const auto& path : selectedFiles) {
                std::cout << "Selected filename: " << path.string() << std::endl;
            }
            fileDialog.ClearSelected();
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
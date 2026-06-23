#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include "history.h"
#include "interface.h"
#include "app_state.h"

using json = nlohmann::json;

struct BookData {
    std::string title;
    std::string note;
    int pageStart;
    int pageEnd;
    std::string date;
};

BookData bookData;

AppState state;

void fetchUserData() {
    std::ifstream file("/Users/klamerus/HOME/imgui_book/save_data/user_data.json");

    if (!file.is_open()) {
    printf("failed to open json file\n");
    return;
    }   

    try{
        json j = json::parse(file);
        bookData.title = j["title"];
        bookData.date = j["date"];
        bookData.note = j["note"];
        bookData.pageStart = j["page_start"];
        bookData.pageEnd = j["page_end"];
        printf("%s\n", bookData.title.c_str());
        printf("%s\n", bookData.note.c_str());
        printf("%s\n", bookData.date.c_str());
        printf("Started on page: %d, Finished on page: %d\n", bookData.pageStart, bookData.pageEnd);
    }   catch(const std::exception& e) {
        printf("json parse error: %s\n", e.what());
    }
}

int main(int, char**)
{
    glfwSetErrorCallback([](int error, const char* description) {
        fprintf(stderr, "GLFW Error %d: %s\n", error, description);
    });

    if (!glfwInit())
        return 1;

    //OpenGL setup
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "My ImGui App", nullptr, nullptr);
    if (!window)
        return 1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // VSync

    // Setup Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_None;      // Important

    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");


    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
        ImGui::SetNextWindowBgAlpha(0.0f);

        ImGui::Begin("##Main", nullptr,
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoBringToFrontOnFocus |
            ImGuiWindowFlags_NoNavFocus |
            ImGuiWindowFlags_NoBackground);

        ImGui::Text("ImGui Book App");
        ImGui::Separator();
        AppInterface::DisplayNav(state);
        NoteHistory::DisplayHistory();

        if(state.viewReadingLogShowing) {
            ImGui::Text("Reading log showing");
            if(ImGui::Button("exit")) {
                state.viewReadingLogShowing = false;
            }
        }

        if(state.addBookPageShowing) {
            ImGui::Text("add book here!");
            if(ImGui::Button("exit")) {
                state.addBookPageShowing = false;
            }
        }

        if(state.settingsPageShowing) {
            ImGui::Text("settings");
            if(ImGui::Button("exit")) {
                state.settingsPageShowing = false;
            }
        }

        if (ImGui::Button("Click Me"))
        {
            fetchUserData();
        }

        //ImGui::ShowStyleEditor();
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.12f, 0.12f, 0.15f, 1.00f);
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

    return 0;
}
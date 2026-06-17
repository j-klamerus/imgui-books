#include <iostream>
#include "interface.h"
#include "imgui.h"

namespace AppInterface {
    void DisplayNav() {
        ImGui::Text("App Name");
        if(ImGui::Button("View History")) {
            std::cout << "view history clicked" << std::endl;
        }
        if(ImGui::Button("Add New Read")) {
            std::cout << "add new read clicked" << std::endl;
        }
        if(ImGui::Button("Settings")) {
            std::cout << "settings clicked" << std::endl;
        }
    }
}
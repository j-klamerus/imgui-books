#include <iostream>
#include "interface.h"
#include "imgui.h"
#include "addBook.h"
#include "app_state.h"

namespace AppInterface {
    float buttonWidth = 100.0f;
    float buttonHeight = 20.0f;


    void DisplayNav(AppState& state) {
        //this line needs to be declared here because it needs active imgui context to access available region
        float availableWidth = ImGui::GetContentRegionAvail().x;
        ImGui::SetCursorPosX((availableWidth - (buttonWidth * 3)) * 0.5f);
        if(ImGui::Button("View History", {buttonWidth, buttonHeight})) {
            std::cout << "view history clicked" << std::endl;
            state.viewReadingLogShowing = true;
        }
        ImGui::SameLine();
        if(ImGui::Button("Add New Read", {buttonWidth, buttonHeight})) {
            //addBookPageShowing = true;
            std::cout << "add new read clicked" << std::endl;
            state.addBookPageShowing = true;
        }
        ImGui::SameLine();
        if(ImGui::Button("Settings", {buttonWidth, buttonHeight})) {
            std::cout << "settings clicked" << std::endl;
            state.settingsPageShowing = true;
        }
    }
}
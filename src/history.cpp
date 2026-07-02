#include "history.h"
#include "imgui.h"
#include <vector>
#include <random>
#include <iostream>

namespace NoteHistory {

    const int NUMBER_OF_COLUMNS = 52;
    const int NUMBER_OF_ROWS = 7;
    int boxID = 0;
    bool checkboxBool = false;

    float buttonSize = 20.0f;

    //declare history button color shades
    std::vector<std::vector<float>> shades = {
        {47.0f / 255.0f, 255.0f, 0.0f, 0.2f},
        {47.0f / 255.0f, 255.0f, 0.0f, 0.4f},
        {47.0f / 255.0f, 255.0f, 0.0f, 0.6f},
        {47.0f / 255.0f, 255.0f, 0.0f, 0.8f},
        {47.0f / 255.0f, 255.0f, 0.0f, 1.0f}
    };
    
    void DisplayHistory() {
        //int colorIndex = randomNumber();
        /* doesnt work
        float tableWidth = NUMBER_OF_COLUMNS * buttonSize * ImGui::GetStyle().ItemSpacing.x;
        float availableWidth = ImGui::GetContentRegionAvail().x;
        ImGui::SetCursorPosX((availableWidth - tableWidth));
        */
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(52.0f / 255.0f, 152.0f / 255.0f, 219.0f / 255.0f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(52.0f / 255.0f, 152.0f / 255.0f, 219.0f / 255.0f, 1.0f));
            if(ImGui::BeginTable("split", NUMBER_OF_COLUMNS + 1)) {
                for(int i = 0; i < NUMBER_OF_COLUMNS; i++) {
                    ImGui::TableNextColumn();
                    for(int j = 0; j < NUMBER_OF_ROWS; j++) {
                        ImGui::PushID(i * NUMBER_OF_ROWS + j);
                            if(ImGui::Button("", {20, 20})) {
                                std::cout << "clicked " << i * NUMBER_OF_ROWS + j << " button" << std::endl;
                        }
                        ImGui::PopID();
                        //boxID++;
                    }
                }
            ImGui::TableNextColumn();
            ImGui::PushID(364);
            if(ImGui::Button("", {buttonSize, buttonSize})) {
                        std::cout << "clicked " << 364 << " button" << std::endl;
            }
            ImGui::PopID();
        ImGui::PopStyleColor(2); 
        ImGui::EndTable();
        }
    }

    int randomNumber() {

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> distr(0,4);

        int random_number = distr(gen);

        return random_number;
    }
}
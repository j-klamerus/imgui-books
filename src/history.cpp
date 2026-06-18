#include "history.h"
#include "imgui.h"
#include <vector>

namespace NoteHistory {
    const int NUMBER_OF_COLUMNS = 73;
    int boxID = 0;
    bool checkboxBool = false;
    //declare history button color shades
    std::vector<std::vector<float>> shades = {
        {},
        {},
        {},
        {},
        {}
    };
    void DisplayHistory() {
            if(ImGui::BeginTable("split", 73)) {
                for(int i = 0; i < NUMBER_OF_COLUMNS; i++) {

                    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(52.0f / 255.0f, 152.0f / 255.0f, 219.0f / 255.0f, 1.0f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(52.0f / 255.0f, 152.0f / 255.0f, 219.0f / 255.0f, 1.0f));
                    
                    ImGui::TableNextColumn();
                    ImGui::PushID(boxID);
                        ImGui::Button("", {25, 25});
                    ImGui::PopID();
                    boxID++;
                    ImGui::PushID(boxID);
                        ImGui::Button("", {25, 25});
                    ImGui::PopID();
                    boxID++;
                    ImGui::PushID(boxID);
                        ImGui::Button("", {25, 25});
                    ImGui::PopID();
                    boxID++;
                    ImGui::PushID(boxID);
                        ImGui::Button("", {25, 25});
                    ImGui::PopID();
                    boxID++;
                    ImGui::PushID(boxID);
                        ImGui::Button("", {25, 25});
                    ImGui::PopID();
                    boxID++;
                    ImGui::PopStyleColor(2); 
                }
            ImGui::EndTable();
        }
    }
}
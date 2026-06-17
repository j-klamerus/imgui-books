#include "history.h"
#include "imgui.h"

namespace NoteHistory {
    void DisplayHistory() {
        const int NUMBER_OF_COLUMNS = 73;
        int boxID = 0;
        bool checkboxBool = false;

        ImGui::Text("This is the history UI");
            if(ImGui::BeginTable("split", 73)) {
                for(int i = 0; i < NUMBER_OF_COLUMNS; i++) {

                    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(40.0f, 234.0f, 64.0f, 1.0f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(40.0f, 234.0f, 64.0f, 0.5f));
                    
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
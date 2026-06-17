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
                }
            ImGui::EndTable();
        }
    }
}
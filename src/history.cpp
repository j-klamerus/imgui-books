#include "history.h"
#include "imgui.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <vector>
#include <random>
#include <iostream>
#include "book_data.h"
#include "app_state.h"

namespace NoteHistory {

    const int NUMBER_OF_COLUMNS = 52;
    const int NUMBER_OF_ROWS = 7;
    int boxID = 0;
    bool checkboxBool = false;

    float buttonSize = 20.0f;

    using json = nlohmann::json;
    std::vector<BookData> readingLog = {};

    //declare history button color shades
    std::vector<ImVec4> shades = {
        {47.0f / 255.0f, 255.0f, 0.0f, 0.2f},
        {47.0f / 255.0f, 255.0f, 0.0f, 0.4f},
        {47.0f / 255.0f, 255.0f, 0.0f, 0.6f},
        {47.0f / 255.0f, 255.0f, 0.0f, 0.8f},
        {47.0f / 255.0f, 255.0f, 0.0f, 1.0f}
    };

    void DisplayHistory(AppState &state) {
        //int colorIndex = randomNumber();
        /* doesnt work
        float tableWidth = NUMBER_OF_COLUMNS * buttonSize * ImGui::GetStyle().ItemSpacing.x;
        float availableWidth = ImGui::GetContentRegionAvail().x;
        ImGui::SetCursorPosX((availableWidth - tableWidth));
        */
        if(state.initializedHistoryData) {
                if(ImGui::BeginTable("split", NUMBER_OF_COLUMNS + 1)) {
                    for(int i = 0; i < NUMBER_OF_COLUMNS; i++) {
                        ImGui::TableNextColumn();
                        for(int j = 0; j < NUMBER_OF_ROWS; j++) {
                            ImGui::PushID(i * NUMBER_OF_ROWS + j);
                            if(checkReadExists((i * NUMBER_OF_ROWS + j)) /*there exists a read in the readinglog vector with this index + 1 as the # of year */) {
                                // check for additional reads on this day and draw the color of the cell accordingly
                                std::cout << "read exists here" << std::endl;
                            } else {
                                // draw default empty cell if no read exists.
                                std::cout << "read doesnt exist here" << std::endl;
                            }
                            ImGui::PushStyleColor(ImGuiCol_Button, shades[0]);
                            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, shades[0]);
                                if(ImGui::Button("", {20, 20})) {
                                    std::cout << "clicked " << i * NUMBER_OF_ROWS + j << " button" << std::endl;
                            }
                            ImGui::PopStyleColor(2);
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
            ImGui::EndTable();
            }
        } else {
            fetchUserData(state);
        }
    }

    int randomNumber() {

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> distr(0,4);

        int random_number = distr(gen);

        return random_number;
    }

        void fetchUserData(AppState &state) {
        //readingLog.clear();
        //dataFetched = true;
        std::ifstream file("/Users/klamerus/HOME/imgui_book/save_data/user_data.json");
        
        if (!file.is_open()) {
        printf("failed to open json file\n");
        return;
        }   

        try{
            json j = json::parse(file);
            /*bookData.title = j["title"];
            bookData.date = j["date"];
            bookData.note = j["note"];
            bookData.pageStart = j["page_start"];
            bookData.pageEnd = j["page_end"];*/
            for(int i = 0; i < j["reads"].size(); i++) {
                readingLog.push_back({j["reads"][i]["title"],
                    j["reads"][i]["note"],
                    j["reads"][i]["page_start"],
                    j["reads"][i]["page_end"],
                    j["reads"][i]["date"],
                    j["reads"][i]["dayNumberOfRead"],
                    j["reads"][i]["id"]
                });
                //bookData.title = j["reads"][i]["title"];
                //printf("%s\n", bookData.title.c_str());
            }
            //dataFetched = true;
            //printf("%s\n", bookData.title.c_str());
            //printf("%s\n", bookData.note.c_str());
            //printf("%s\n", bookData.date.c_str());
            //printf("Started on page: %d, Finished on page: %d\n", bookData.pageStart, bookData.pageEnd);
            state.initializedHistoryData = true;
        }   catch(const std::exception& e) {
            printf("json parse error: %s\n", e.what());
        }
    }

    bool checkReadExists(int buttonNumber) {
        for(int i = 0; i < readingLog.size(); i++) {
            if(readingLog[i].dayOfYear == buttonNumber) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

}
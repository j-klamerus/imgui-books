#include "imgui.h"
#include "log.h"
#include "nlohmann/json.hpp"
#include "book_data.h"
#include <fstream>
#include <vector>

namespace Log {

    using json = nlohmann::json;
    BookData bookData;
    bool dataFetched;

    std::vector<BookData> readingLog = {};

    void DisplayReadingLog(AppState& state) {
        ImGui::Text("Reading Log!!!!");
        if(!state.initializedReadingLog) {
            fetchUserData();
            state.initializedReadingLog = true;
        }
        //dataFetched = true;
        if(dataFetched) {
            for(const auto& read : readingLog) {
                ImGui::Text("%s", read.title.c_str());
                ImGui::Text("%s", read.note.c_str());
                ImGui::Text("%s", read.date.c_str());
                ImGui::Text("Read %d pages.", read.pageEnd - read.pageStart);
            }
           ImGui::Text("data fetched is true");
        }
    }

    void fetchUserData() {
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
                    j["reads"][i]["id"]
                });
                //bookData.title = j["reads"][i]["title"];
                //printf("%s\n", bookData.title.c_str());
            }
            dataFetched = true;
            //printf("%s\n", bookData.title.c_str());
            //printf("%s\n", bookData.note.c_str());
            //printf("%s\n", bookData.date.c_str());
            //printf("Started on page: %d, Finished on page: %d\n", bookData.pageStart, bookData.pageEnd);
        }   catch(const std::exception& e) {
            printf("json parse error: %s\n", e.what());
        }
    }

    void DisplayIndividualRead() {
        std::vector<BookData> readingLog = {};
        readingLog.push_back(
            {"Book title", "log note", 1, 2, "12-12-12", 1001}
        );
        return;
    }
    /*
        std::string title;
        std::string note;
        int pageStart;
        int pageEnd;
        std::string date;
        int logID;
    */
}
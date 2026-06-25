#include "imgui.h"
#include "log.h"
#include "nlohmann/json.hpp"
#include "book_data.h"
#include <fstream>

namespace Log {

    using json = nlohmann::json;
    BookData bookData;
    bool dataFetched = false;

    void DisplayReadingLog() {
        ImGui::Text("Reading Log!!!!");
        //fetchUserData();
        //dataFetched = true;
        if(dataFetched) {
            ImGui::Text("%s", bookData.title.c_str());
            ImGui::Text("%s", bookData.note.c_str());
            ImGui::Text("%s", bookData.date.c_str());
            ImGui::Text("Started on page: %d, Finished on page: %d\n", bookData.pageStart, bookData.pageEnd);
        }
    }

    /*void fetchUserData() {
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
    }*/
}
#include "addBook.h"
#include "imgui.h"
#include <iostream>
#include "book_data.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <ctime>

using json = nlohmann::json;

namespace AddBook {

    BookData bookData;

    int firstPage = 0;
    int endPage = 0;

    void DisplayAddPage() {

        //display text input and define labeles for each
        static char bookTitleLabel[255] = "Book Title";
        if(ImGui::InputText("##edit", bookTitleLabel, IM_COUNTOF(bookTitleLabel))) {
            bookData.title = bookTitleLabel;
            //std::cout << bookData.title << std::endl;
        }

        static char readDescriptionLabel[255] = "description";
        if (ImGui::InputText("##description", readDescriptionLabel, IM_COUNTOF(readDescriptionLabel))) {
            bookData.note = readDescriptionLabel;
        }

        ImGui::InputInt("##01Page Started", &firstPage);
        bookData.pageStart = firstPage;

        ImGui::InputInt("##02Page Ended", &endPage);
        bookData.pageEnd = endPage;

        if(ImGui::Button("Write to json file")) {
            //std::cout << bookData.pageStart << std::endl;
            //std::cout << bookData.pageEnd << std::endl;
            //get time
            time_t timestamp;
            time(&timestamp);
            bookData.date = ctime(&timestamp);
            
            UploadBookData(bookData);
        }

    };

    int UploadBookData(BookData data) {
            json userData;

            //load json file
            std::ifstream in("/Users/klamerus/HOME/imgui_book/save_data/user_data.json");
            if(in.is_open()) {
                in >> userData;
                std::cout << "opened file" << std::endl;
            }

            // enter user read data
            userData["reads"].push_back({
                {"id", 3},
                {"title", data.title},
                {"note", data.note},
                {"page_start", data.pageStart},
                {"page_end", data.pageEnd},
                {"date", data.date}
            });

            //save json file
            std::ofstream out("/Users/klamerus/HOME/imgui_book/save_data/user_data.json");
            out << userData.dump(4);
            
            return 0;
        }
}
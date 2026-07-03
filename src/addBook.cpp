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

        ImGui::Text("Page Started:");
        ImGui::InputInt("##01Page Started", &firstPage);
        bookData.pageStart = firstPage;

        ImGui::Text("Page Ended:");
        ImGui::InputInt("##02Page Ended", &endPage);
        bookData.pageEnd = endPage;

        if(ImGui::Button("Write to json file")) {
            //std::cout << bookData.pageStart << std::endl;
            //std::cout << bookData.pageEnd << std::endl;
            if(bookData.title == "" || bookData.note == "" || bookData.title == "Book Title" || bookData.note == "description") {
                std::cout << "Enter valid book title and note." << std::endl;
                return;
            }
            if(bookData.pageStart == 0 || bookData.pageEnd == 0 || bookData.pageStart > bookData.pageEnd) {
                std::cout << "Enter valid page start and page end." << std::endl;
                return;
            }
            //get time in "Thu Jul  2 15:49:42 2026" format. 
            //need to get # day of year  
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
                {"id", checkMostRecentID(userData)},
                {"title", data.title},
                {"note", data.note},
                {"page_start", data.pageStart},
                {"page_end", data.pageEnd},
                {"date", data.date}
            });

            //save json file
            std::ofstream out("/Users/klamerus/HOME/imgui_book/save_data/user_data.json");
            out << userData.dump(4);
            //checkMostRecentID(userData);
            return 0;
        }

    int checkMostRecentID(json userData) {
        //std::cout << userData["reads"].size() << std::endl;
        return userData["reads"].size() + 1;
    }
}
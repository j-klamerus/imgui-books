#include "addBook.h"
#include "imgui.h"
#include <iostream>
#include "book_data.h"
#include "nlohmann/json.hpp"
#include <fstream>

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
            UploadBookData(bookData);
        }

    };

    int UploadBookData(BookData data) {
            json userData;

            std::ofstream file("user_data.json");

            if (file.is_open()) {
                file << userData.dump(4); // Pretty-print with 4-space indentation
                file.close();
            }

            return 0;
        }
}
#include "addBook.h"
#include "imgui.h"
#include <iostream>
#include "book_data.h"

namespace AddBook {

    BookData bookData;

    int firstPage = 0;
    int endPage = 0;

    void DisplayAddPage() {

        //display text input and define labeles for each
        static char bookTitleLabel[255] = "Book Title";
        if(ImGui::InputText("##edit", bookTitleLabel, IM_COUNTOF(bookTitleLabel))) {
            bookData.title = bookTitleLabel;
            std::cout << bookData.title << std::endl;
        }

        static char readDescriptionLabel[255] = "description";
        if (ImGui::InputText("##description", readDescriptionLabel, IM_COUNTOF(readDescriptionLabel))) {
            bookData.note = readDescriptionLabel;
        }

        ImGui::InputInt("Page Started", &firstPage);
        bookData.pageStart = firstPage;

        ImGui::InputInt("Page Ended", &endPage);
        bookData.pageEnd = endPage;

        if(ImGui::Button("print page start and end")) {
            std::cout << bookData.pageStart << std::endl;
            std::cout << bookData.pageEnd << std::endl;
        }
    };
}
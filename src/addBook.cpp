#include "addBook.h"
#include "imgui.h"
#include <iostream>

namespace AddBook {
    void DisplayAddPage() {
        //display text input and define labeles for each
        static char bookTitleLabel[255] = "Book Title";
        ImGui::InputText("##edit", bookTitleLabel, IM_COUNTOF(bookTitleLabel));

        static char readDescriptionLabel[255] = "description";
        ImGui::InputText("##description", readDescriptionLabel, IM_COUNTOF(readDescriptionLabel));

        static char firstPageLabel [14] = "Page Started";
        //int firstPage = 10;
        static int vec4i[4] = { 1, 5, 100, 255 };
        ImGui::InputInt2(firstPageLabel, vec4i);
    };
}
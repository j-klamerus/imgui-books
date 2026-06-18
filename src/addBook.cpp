#include "addBook.h"
#include "imgui.h"
#include <iostream>

namespace AddBook {
    void DisplayAddPage(bool addBookPageShowing) {
        if(addBookPageShowing) {
            ImGui::Text("ADD BOOK PAGE");
        }
        std::cout << "showing add book page" << std::endl;
    };
}
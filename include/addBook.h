#pragma once
#include "book_data.h"
#include "nlohmann/json.hpp"

namespace AddBook {
    void DisplayAddPage();
    int UploadBookData(BookData data);
    int checkMostRecentID(nlohmann::json userData);
}
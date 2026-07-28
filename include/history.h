#pragma once
#include "app_state.h"
#include "book_data.h"

namespace NoteHistory {
    void DisplayHistory(AppState &state);
    int randomNumber();
    void fetchUserData(AppState &state);
    bool checkReadExists(int dayNumber);
    void logBookData(const std::vector<BookData>& books);
}
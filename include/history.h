#pragma once
#include "app_state.h"

namespace NoteHistory {
    void DisplayHistory(AppState &state);
    int randomNumber();
    void fetchUserData(AppState &state);
    bool checkReadExists(int dayNumber);
}
#pragma once

#include "nlohmann/json.hpp"
#include "book_data.h"
#include "app_state.h"

namespace Log {
    void DisplayReadingLog(AppState& state);
    void fetchUserData();
    void DisplayIndividualRead();
}


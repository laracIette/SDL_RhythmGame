#pragma once

#include <vector>

#include "../Option/Option.h"

namespace RythmGame::Game::Settings
{
    class Category
    {
        std::vector<Option *> options;

    public:
        Category();
        ~Category();

        void Draw();
    };
}

#pragma once

#include <vector>

#include "../Category/Category.h"

namespace RythmGame::Game::Settings
{

    class Window
    {
        std::vector<Category *> categories;

    public:
        Window();
        ~Window();

        void Draw();
    };

}
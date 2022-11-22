#pragma once

#include <vector>
#include <SDL.h>

#include "../../Utils/GameSettings.h"

#include "../../../RythmGame.Graphics/Image/Image.h"

#include "../Category/Category.h"

#include "../../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Framework;

namespace RythmGame::Game::Settings
{

    class Window
    {
        std::vector<Category *> categories;

        SDL_Rect *backgroundRect;
        RGB backgroundColor;

    public:
        Window();
        ~Window();

        void Update();

        void Draw();
    };

}
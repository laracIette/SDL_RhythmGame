#pragma once

#include <vector>
#include <SDL.h>
#include <json.hpp>
#include <fstream>
#include <map>

#include "../Option/Types/Check/Check.h"
#include "../Option/Types/Value/Value.h"
#include "../Option/Types/Slider/Slider.h"
#include "../Option/Types/Options/Options.h"

#include "../../Utils/GameSettings.h"

#include "../../../RythmGame.Graphics/Image/Image.h"

#include "../Category/Category.h"

#include "../../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Framework;
using namespace RythmGame::Game::Settings::Option;

using json = nlohmann::json;

namespace RythmGame::Game::Settings
{

    class Window
    {
        std::vector<Category *> categories;

        SDL_Rect *backgroundRect;
        RGB backgroundColor;

        json data;

        float posY;

    public:
        Window();
        ~Window();

        void Update();

        void Draw();
    };

}
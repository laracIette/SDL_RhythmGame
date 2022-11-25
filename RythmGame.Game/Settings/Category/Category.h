#pragma once

#include <vector>
#include <SDL.h>
#include <string>
#include <map>

#include "../Option/Types/Check/Check.h"
#include "../Option/Types/Value/Value.h"
#include "../Option/Types/Slider/Slider.h"

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"

#include "../../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Framework;
using namespace RythmGame::Game::Settings::Option;

namespace RythmGame::Game::Settings
{
    class Category
    {
        TextTTF *title;

        std::vector<OptionTemplate *> options;

        SDL_Rect *backgroundRect;
        RGB backgroundColor;

        std::pair<int, int> posPair;

    public:
        Category( std::string title, std::vector<OptionTemplate *> optionsVector );
        ~Category();

        int Update( int posY );

        void Draw();

        std::map<std::string, float> ChangeValue();
    };
}

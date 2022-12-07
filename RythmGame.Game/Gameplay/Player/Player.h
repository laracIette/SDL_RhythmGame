#pragma once

#include "../../Utils/Metrics.h"
#include "../../Utils/GameSettings.h"
#include "../../Events/InputManager.h"

#include "../../../RythmGame.Graphics/Image/Image.h"

#include "../../../RythmGame.Graphics/Renderable.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Graphics;

namespace RythmGame::Game::Gameplay
{

    class Player : public Renderable
    {
        static const int nIMAGES{ 6 };

        Image *images[nIMAGES];
        bool isImageShown[nIMAGES]{ false };

        enum ImagesStates {
            HorizontalDefault = 0,
            UpLeft,
            UpRight,
            DownLeft,
            DownRight,
            VerticalDefault
        };

    public:
        Player();
        ~Player();

        void Input();
    };

}

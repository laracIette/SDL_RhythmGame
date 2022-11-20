#pragma once

#include "../../RythmGame.Graphics/Image/Image.h"
#include "../Utils/GameSettings.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;


namespace RythmGame::Game::Gameplay
{

    class Dim
    {
        Image *horizontalDim;
        Image *verticalDim;

    public:
        Dim()
        {
            horizontalDim = new Image(
                "assets/Skins/BaseSkin/dim0.png",
                {0, 0, 1920, 1080},
                {Default::WIDTH/2, Default::HEIGHT/2, Default::WIDTH, Default::HEIGHT}
            );
            verticalDim = new Image(
                "assets/Skins/BaseSkin/dim1.png",
                {0, 0, 1920, 1080},
                {Default::WIDTH/2, Default::HEIGHT/2, Default::WIDTH, Default::HEIGHT}
            );
        }
        ~Dim() {}

        void DrawHorizontalDim()
        {
            horizontalDim->Draw();
        }
        void DrawVerticalDim()
        {
            verticalDim->Draw();
        }
    };

}

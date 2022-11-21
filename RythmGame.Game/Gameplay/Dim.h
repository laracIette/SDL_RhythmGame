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
                {1920/2, 1080/2, 1920, 1080}
            );
            verticalDim = new Image(
                "assets/Skins/BaseSkin/dim1.png",
                {0, 0, 1920, 1080},
                {1920/2, 1080/2, 1920, 1080}
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

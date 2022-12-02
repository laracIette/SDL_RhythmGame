#pragma once

#include "../../RythmGame.Graphics/Image/Image.h"

using namespace RythmGame::Graphics;


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
                {1920/2, 1080/2, 1920, 1080},
                RenderGameplay,
                6
            );
            verticalDim = new Image(
                "assets/Skins/BaseSkin/dim1.png",
                {1920/2, 1080/2, 1920, 1080},
                RenderGameplay,
                6
            );
        }
        ~Dim() {}

        void ShowHorizontalDim()
        {
            horizontalDim->IsShown( true );
        }
        void ShowVerticalDim()
        {
            verticalDim->IsShown( true );
        }
    };

}

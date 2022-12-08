#pragma once

#include "../../RythmGame.Graphics/Image/Positions/ImageTopLeft.h"

using namespace RythmGame::Graphics;


namespace RythmGame::Game::Gameplay
{

    class Dim
    {
        ImageTopLeft *horizontalDim;
        ImageTopLeft *verticalDim;

    public:
        Dim()
        {
            horizontalDim = new ImageTopLeft(
                "assets/Skins/BaseSkin/dim0.png",
                {0, 0, 1920, 1080},
                RenderGameplay,
                6
            );
            verticalDim = new ImageTopLeft(
                "assets/Skins/BaseSkin/dim1.png",
                {0, 0, 1920, 1080},
                RenderGameplay,
                6
            );
        }
        ~Dim() {}

        void ShowHorizontalDim()
        {
            horizontalDim->Show();
        }
        void ShowVerticalDim()
        {
            verticalDim->Show();
        }
    };

}

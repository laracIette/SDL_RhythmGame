#pragma once

#include "../../RythmGame.Graphics/Background.h"
#include "../Utils/GameSettings.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;


namespace RythmGame::Game::Gameplay
{

    class Dim
    {
        Background *horizontalDim;
        Background *verticalDim;

    public:
        Dim()
        {
            horizontalDim = new Background(
                "assets/Skins/BaseSkin/dim0.png",
                RenderGameplay
            );
            verticalDim = new Background(
                "assets/Skins/BaseSkin/dim1.png",
                RenderGameplay
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

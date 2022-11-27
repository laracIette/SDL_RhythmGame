#pragma once

#include <SDL.h>

#include "SettingsFile.h"

#include "../../RythmGame.Graphics/BoxRoundedCorners.h"
#include "../../RythmGame.Graphics/TextTTF/TextTTF.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Settings
{

    class SettingBox
    {
        BoxRoundedCorners *backgroundBox;

        SDL_Rect dest;

        TextTTF *textTTF;

    public:
        SettingBox( std::string text, int posX, int posY )
        {
            textTTF = new TextTTF( text, optionFont, posX, posY );

            backgroundBox = new BoxRoundedCorners(
                textTTF->GetRect(),
                {50, 50, 50},
                "assets/UI/Settings/SettingBoxRoundedCorner.png"
            );

            dest = dest;
        }
        ~SettingBox() {}

        void DrawBackgroundBox()
        {
            backgroundBox->Draw();
        }

        void DrawText()
        {
            textTTF->Draw();
        }
    };


}

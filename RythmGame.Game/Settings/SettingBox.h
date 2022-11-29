#pragma once

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include <string>

#include "SettingsFile.h"

#include "../../RythmGame.Graphics/BoxRoundedCorners.h"
#include "../../RythmGame.Graphics/TextTTF/TextTTF.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Settings
{

    class SettingBox
    {
        BoxRoundedCorners *backgroundBox;

        TextTTF *textTTF;

        std::string name;

    protected:
        bool isSelected;

        int posY;

    public:
        SettingBox( std::string _name, int _posY )
        {
            isSelected = false;

            name = _name;

            posY = _posY;
        }
        ~SettingBox() {}


        void Init()
        {
            textTTF = new TextTTF( name, optionFont, 100, posY, RenderSettings, 6 );

            backgroundBox = new BoxRoundedCorners(
                textTTF->GetRect(),
                RenderSettings,
                7,
                {50, 50, 50},
                "assets/UI/Settings/SettingBoxRoundedCorner.png"
            );
        }

        void Scroll( int _posY )
        {
            textTTF->Update( posY + _posY );
            backgroundBox->SetY( posY + _posY );
        }

        void Update()
        {
            textTTF->Hoover();

            if( textTTF->IsHooverLeftClicked() )
            {
                isSelected = !isSelected;
            }

            if( textTTF->IsNotHooverLeftClicked() )
            {
                isSelected = false;
            }

        }

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

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

        bool isNewSelected;

    protected:
        bool isSelected;

        int posY;

    public:
        SettingBox( std::string _name, int _posY )
        {
            isSelected = false;
            isNewSelected = false;

            name = _name;

            posY = _posY;
        }
        ~SettingBox() {}


        void Init()
        {
            textTTF = new TextTTF(
                name,
                optionFont,
                100,
                posY,
                RenderSettings,
                5
            );

            backgroundBox = new BoxRoundedCorners(
                textTTF->GetRect(),
                RenderSettings,
                7,
                SettingsSettingBoxGray,
                "assets/UI/Settings/SettingBoxRoundedCorner.png"
            );
        }

        void Scroll( int _posY )
        {
            textTTF->Update( posY + _posY );
            backgroundBox->SetY( posY + _posY );
        }

        void SwitchSelected()
        {
            isSelected = isNewSelected;
        }

        void Update()
        {
            backgroundBox->Show();

            textTTF->Hoover();
            textTTF->Show();

            if( textTTF->IsHooverLeftClicked() )
            {
                isNewSelected = !isSelected;
            }

            if( textTTF->IsNotHooverLeftClicked() )
            {
                isNewSelected = false;
            }

        }

    };


}

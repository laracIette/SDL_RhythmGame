#pragma once

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include <string>

#include "SettingsFile.h"

#include "../../RythmGame.Graphics/BoxRoundedCorners/BoxRoundedCorners.h"
#include "../../RythmGame.Graphics/TextTTF/TextTTF.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Settings
{

    class SettingBox
    {
        BoxRoundedCorners *backgroundBox;

        TextTTF *textTTF;

        bool isNewSelected;

    protected:
        bool isSelected;

        float posY;

        std::string category, name;

    public:
        SettingBox( std::string _category, std::string _name, float _y )
        {
            isSelected    = false;
            isNewSelected = false;

            category = _category;
            name     = _name;

            posY = _y;
        }
        ~SettingBox() {}


        void Init()
        {
            textTTF = new TextTTF(
                name,
                optionFont,
                100,
                posY,
                {{RenderSettings, 5}}
            );

            backgroundBox = new BoxRoundedCorners(
                textTTF->GetRect(),
                {{RenderSettings, 7}},
                SettingsSettingBoxGray,
                "assets/UI/Settings/SettingBoxRoundedCorner.png"
            );
        }

        void Scroll( float _y )
        {
            textTTF->Update( posY + _y );
            backgroundBox->SetY( posY + _y );
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

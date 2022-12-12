#pragma once

#include <string>

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"
#include "../../../RythmGame.Graphics/BoxRoundedCorners.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Settings
{

    class CategoryTemplate
    {
        TextTTF *text;

        std::string name;

        float posY;

        BoxRoundedCorners *backgroundBox;

        float boxHeight;

    public:
        CategoryTemplate( std::string _name, float _y, float _boxHeight )
        {
            name = _name;
            posY = _y;

            boxHeight = _boxHeight;
        }
        ~CategoryTemplate() {}

        void InitCategoryName()
        {
            text = new TextTTF(
                name,
                categoryTitleFont,
                0,
                posY,
                {{RenderSettings, 7}}
            );

            backgroundBox = new BoxRoundedCorners(
                {0, posY, 1920/3, boxHeight},
                {{RenderSettings, 8}},
                SettingsCategoryGray,
                "assets/UI/Settings/SettingCategoryRoundedCorner.png"
            );
        }

        void ScrollCategoryName( float _y )
        {
            text->Update( posY + _y );
            backgroundBox->SetY( posY + _y );
            backgroundBox->Show();
            text->Show();
        }
    };

}

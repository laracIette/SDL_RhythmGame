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

        int posY;

        BoxRoundedCorners *backgroundBox;

        int boxHeight;

    public:
        CategoryTemplate( std::string _name, int _posY, int _boxHeight )
        {
            name = _name;
            posY = _posY;

            boxHeight = _boxHeight;
        }
        ~CategoryTemplate() {}

        void InitCategoryName()
        {
            text = new TextTTF( name, categoryTitleFont, 0, posY, RenderSettings, 7 );

            backgroundBox = new BoxRoundedCorners(
                {0, resize( posY ), resize( 1920/3 ), resize( boxHeight )},
                RenderSettings,
                8,
                {60, 60, 60},
                "assets/UI/Settings/SettingCategoryRoundedCorner.png"
            );
        }

        void ScrollCategoryName( int _posY )
        {
            text->Update( posY + _posY );
            backgroundBox->SetY( posY + _posY );
        }

        void DrawCategoryName()
        {
            backgroundBox->Draw();
            text->Draw();
        }
    };

}

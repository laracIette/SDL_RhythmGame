#include "OptionsBox.h"

namespace RythmGame::Graphics
{

    OptionsBox::OptionsBox( std::vector<std::string> optionsVector, int posY )
    {
        int newPosY{ posY };
        for( std::string option : optionsVector )
        {
            options.push_back( new TextTTF( option, optionFont, 0, newPosY ) );
            newPosY += FONT_SIZE_OPTION;
        }

        box = new BoxRoundedCorners(
            {100, posY, 1920/3, newPosY},
            {50, 50, 50},
            "assets/UI/Settings/SettingBoxRoundedCorner.png"
        );
    }

    OptionsBox::~OptionsBox()
    {
    }

    void OptionsBox::DrawOptionsBox()
    {
        box->Draw();
        for( TextTTF *text : options )
        {
            text->Draw();
        }
    }

}

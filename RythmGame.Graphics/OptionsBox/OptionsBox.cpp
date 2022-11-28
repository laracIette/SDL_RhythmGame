#include "OptionsBox.h"

namespace RythmGame::Graphics
{

    OptionsBox::OptionsBox( std::vector<std::string> _optionsVector, int _posY )
    {
        int newPosY{ _posY };
        for( std::string option : _optionsVector )
        {
            options.push_back( new TextTTF( option, optionFont, 100, newPosY ) );
            newPosY += FONT_SIZE_OPTION;
        }

        box = new BoxRoundedCorners(
            {resize( 100 ), resize( _posY ), resize( 1920/3-200 ), resize( newPosY )},
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
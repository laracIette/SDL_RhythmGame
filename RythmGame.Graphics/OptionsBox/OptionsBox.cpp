#include "OptionsBox.h"

namespace RythmGame::Graphics
{

    OptionsBox::OptionsBox( std::vector<std::string> _optionsVector, int _posY )
    {
        int newPosY{ _posY };
        for( std::string option : _optionsVector )
        {
            options.push_back( new TextTTF( option, optionFont, 100, newPosY, RenderSettings, 4 ) );
            newPosY += FONT_SIZE_OPTION_WITH_SPACE;
        }

        box = new BoxRoundedCorners(
            {resize( 100 ), resize( _posY ), resize( 1920/3-200 ), resize( newPosY )},
            RenderSettings,
            5,
            SettingsSettingBoxGray,
            "assets/UI/Settings/SettingBoxRoundedCorner.png"
        );
    }

    OptionsBox::~OptionsBox()
    {
    }

    void OptionsBox::Scroll( int _posY )
    {
        box->SetY( _posY );
        int newPosY{ _posY };
        for( TextTTF *text : options )
        {
            text->Update( newPosY );
            newPosY += FONT_SIZE_OPTION_WITH_SPACE;
        }
    }

    void OptionsBox::Update()
    {
        box->IsShown( true );
        for( TextTTF *text : options )
        {
            text->IsShown( true );
        }
    }

}

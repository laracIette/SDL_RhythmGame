#include "OptionsBox.h"

namespace RythmGame::Graphics
{

    OptionsBox::OptionsBox( std::vector<std::string> &_optionsVector, int _posY )
    {
        posY = _posY;

        int newPosY{ posY };
        for( std::string option : _optionsVector )
        {
            options.push_back( new TextTTF( option, optionFont, 100, newPosY, RenderSettings, 4 ) );
            newPosY += FONT_SIZE_OPTION_WITH_SPACE;
        }

        box = new BoxRoundedCorners(
            {resize( 80 ), resize( posY-20 ), resize( 1920/3-160 ), resize( newPosY-posY+40 )},
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
        box->SetY( posY + _posY - 20 );
        int newPosY{ posY + _posY };
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

    int OptionsBox::CheckClicked()
    {
        for( int i{ 0 }; i < options.size(); ++i )
        {
            if( options[i]->IsHooverLeftClicked() ) return i;
        }
        return -1;
    }

}

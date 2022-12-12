#include "OptionsBox.h"

namespace RythmGame::Graphics::Settings
{

    OptionsBox::OptionsBox( std::vector<std::string> &_optionsVector, float _y )
    {
        posY = _y;

        float newPosY{ posY };
        for( std::string option : _optionsVector )
        {
            options.push_back(
                new TextTTF(
                    option,
                    optionFont,
                    100,
                    newPosY,
                    {{RenderSettings, 3}}
                )
            );
            newPosY += FONT_SIZE_OPTION_WITH_SPACE;
        }

        box = new BoxRoundedCorners(
            {80, posY-20, 1920/3-160, newPosY-posY+40},
            {{RenderSettings, 4}},
            SettingsSettingBoxGray,
            "assets/UI/Settings/SettingBoxRoundedCorner.png"
        );
    }

    OptionsBox::~OptionsBox()
    {
    }

    void OptionsBox::Scroll( float _y )
    {
        box->SetY( posY + _y - 20 );
        float newPosY{ posY + _y };
        for( TextTTF *text : options )
        {
            text->Update( newPosY );
            newPosY += FONT_SIZE_OPTION_WITH_SPACE;
        }
    }

    void OptionsBox::Update()
    {
        box->Show();
        for( TextTTF *text : options )
        {
            text->Show();
        }
    }

    void OptionsBox::CheckClicked( int &_index )
    {
        _index = -1;

        for( int i{ 0 }; i < options.size(); ++i )
        {
            if( options[i]->IsHooverLeftClicked() )
            {
                _index = i;
                break;
            }
        }
    }

}

#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Check : public OptionTemplate
    {
        Image *checkBoxOn;
        Image *checkBoxOff;

        bool isOn;

    public:
        Check( std::string text, bool value )
         : OptionTemplate( text )
        {
            checkBoxOn = new Image(
                "assets/UI/Settings/Option/checkBoxOn.png",
                {10, 0, (float)this->text->W(), (float)this->text->H()}
            );
            checkBoxOff = new Image(
                "assets/UI/Settings/Option/checkBoxOff.png",
                {10, 0, (float)this->text->W(), (float)this->text->H()}
            );

            isOn = value;
        }

        void Update( int posY );
        void Draw();
    };

}
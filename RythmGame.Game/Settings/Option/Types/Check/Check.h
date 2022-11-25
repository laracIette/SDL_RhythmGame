#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Check : public OptionTemplate
    {
        Image *checkBoxOn;
        Image *checkBoxOff;

    public:
        Check( std::string text, bool value )
         : OptionTemplate( text, value, TypeCheck )
        {
            checkBoxOn = new Image(
                "assets/UI/Settings/Option/checkBoxOn.png",
                {10, 0, (float)this->text->W(), (float)this->text->H()},
                TopLeft
            );
            checkBoxOff = new Image(
                "assets/UI/Settings/Option/checkBoxOff.png",
                {10, 0, (float)this->text->W(), (float)this->text->H()},
                TopLeft
            );
        }

        std::pair<int, int> Update( int posY );
        void Draw();
    };

}
#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Slider : public OptionTemplate
    {
        float value, min, max;

    public:
        Slider( std::string text, float value, float min, float max )
         : OptionTemplate( text )
        {
            this->value = value;
            this->min = min;
            this->max = max;
        }

        void Update( int posY );
        void Draw();
    };

}
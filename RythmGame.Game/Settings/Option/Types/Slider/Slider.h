#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Slider : public OptionTemplate
    {
        float min, max;

    public:
        Slider( std::string text, float value, float min, float max )
         : OptionTemplate( text, value, TypeSlider )
        {
            this->min = min;
            this->max = max;
        }

        std::pair<int, int> Update( int posY );
        void Draw();
    };

}
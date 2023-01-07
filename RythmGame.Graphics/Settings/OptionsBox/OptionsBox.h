#pragma once

#include <vector>
#include <string>

#include "../../TextTTF/TextTTF.h"
#include "../../BoxRoundedCorners/BoxRoundedCorners.h"

namespace RythmGame::Graphics::Settings
{

    class OptionsBox
    {
        std::vector<TextTTF *> options;
        BoxRoundedCorners *box;

        float posY;

    public:
        OptionsBox( std::vector<std::string> &_optionsVector, float _y );
        ~OptionsBox();

        void Scroll( float _y );

        void Update();

        void CheckClicked( int &_index );
    };

}
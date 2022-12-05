#pragma once

#include <vector>
#include <string>

#include "../../TextTTF/TextTTF.h"
#include "../../BoxRoundedCorners.h"

namespace RythmGame::Graphics::Settings
{

    class OptionsBox
    {
        std::vector<TextTTF *> options;
        BoxRoundedCorners *box;

        int posY;

    public:
        OptionsBox( std::vector<std::string> &_optionsVector, int _posY );
        ~OptionsBox();

        void Scroll( int _posY );

        void Update();

        void CheckClicked( int &_index );
    };

}
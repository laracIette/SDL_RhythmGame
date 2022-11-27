#pragma once

#include <vector>
#include <string>

#include "../TextTTF/TextTTF.h"
#include "../BoxRoundedCorners.h"

namespace RythmGame::Graphics
{

    class OptionsBox
    {
        std::vector<TextTTF *> options;
        BoxRoundedCorners *box;

    public:
        OptionsBox( std::vector<std::string> optionsVector, int posY );
        ~OptionsBox();

        void DrawOptionsBox();
    };

}
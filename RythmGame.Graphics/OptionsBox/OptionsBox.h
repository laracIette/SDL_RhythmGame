#pragma once

#include <vector>
#include <string>

#include "../TextTTF/TextTTF.h"
#include "../BoxRoundedCorners.h"
#include "../RenderObject.h"

namespace RythmGame::Graphics
{

    class OptionsBox : public RenderObject
    {
        std::vector<TextTTF *> options;
        BoxRoundedCorners *box;

    public:
        OptionsBox( std::vector<std::string> _optionsVector, int _posY );
        ~OptionsBox();

        void Draw();
    };

}
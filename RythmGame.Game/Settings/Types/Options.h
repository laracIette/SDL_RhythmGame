#pragma once

#include <vector>
#include <string>

#include "../SettingBox.h"

#include "../../../RythmGame.Graphics/OptionsBox/OptionsBox.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Settings
{

    class Options : public SettingBox
    {
    protected:
        int index;

        OptionsBox *optionsBox;
        std::vector<std::string> vec;

    public:
        Options( std::string name, int posX, int posY ) : SettingBox( name, posX, posY )
        {}

        void Init( int posY )
        {
            optionsBox = new OptionsBox( vec, posY );
        }

        void Draw()
        {
            DrawBackgroundBox();
            optionsBox->DrawOptionsBox();
            DrawText();
        }

    };

}

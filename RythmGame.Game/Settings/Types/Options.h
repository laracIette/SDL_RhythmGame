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
        Options( std::string name, int posY ) :
            SettingBox(
                name,
                posY
            )
        {
        }

        void InitOptions()
        {
            Init();
            optionsBox = new OptionsBox( vec, posY );
        }

        void UpdateOptions()
        {
            Update();
        }

        void DrawOptions()
        {
            DrawBackgroundBox();
            if( isSelected )
            {
                optionsBox->Draw();
            }
            else
            {
                DrawText();
            }
        }

    };

}

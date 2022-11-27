#pragma once

#include <vector>

#include "SettingDimension.h"
#include "SettingFPS.h"

namespace RythmGame::Game::Settings::Video
{

    class Category
    {
        std::vector<Options *> settings;

    public:
        Category( int posY )
        {
            settings.push_back( new SettingDimension( 50, posY ) );
            settings.push_back( new SettingFPS( 50, posY ) );
        }

        void Draw()
        {
            for( Options *setting : settings )
            {
                setting->Draw();
            }
        }

    };


}
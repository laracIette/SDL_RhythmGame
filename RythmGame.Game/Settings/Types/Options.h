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
        Options( std::string _name, int _posY ) :
            SettingBox(
                _name,
                _posY
            )
        {
        }

        void InitOptions()
        {
            Init();
            optionsBox = new OptionsBox( vec, posY );
        }

        void ScrollOptions( int _posY )
        {
            Scroll( _posY );
            optionsBox->Scroll( _posY );
        }

        void UpdateOptions( std::string _category, std::string _name )
        {
            Update();

            if( isSelected )
            {
                optionsBox->Update();

                int newIndex{ optionsBox->CheckClicked() };
                if( (newIndex != -1) && (newIndex != index) )
                {
                    index = newIndex;

                    settingsFile->data[_category][_name]["index"] = index;
                    settingsFile->writeData = true;
                }
            }
            else
            {
                GetText()->IsShown( true );
            }

            SwitchSelected();
        }

    };

}

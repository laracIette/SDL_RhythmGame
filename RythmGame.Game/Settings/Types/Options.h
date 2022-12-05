#pragma once

#include <vector>
#include <string>

#include "../SettingBox.h"

#include "../../../RythmGame.Graphics/Settings/OptionsBox/OptionsBox.h"

using namespace RythmGame::Graphics::Settings;

namespace RythmGame::Game::Settings
{

    class Options : public SettingBox
    {
        int newIndex;

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

                optionsBox->CheckClicked( newIndex );
                if( (newIndex != -1) && (newIndex != index) )
                {
                    index = newIndex;

                    settingsFile->data[_category][_name]["index"] = index;
                    settingsFile->isWriteData = true;
                }
            }

            SwitchSelected();
        }

    };

}

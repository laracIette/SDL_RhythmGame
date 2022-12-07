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
        Options( std::string _category, std::string _name, float _y ) :
            SettingBox(
                _category,
                _name,
                _y
            )
        {
        }

        void InitOptions()
        {
            Init();
            optionsBox = new OptionsBox( vec, posY );
        }

        void ScrollOptions( float _y )
        {
            Scroll( _y );
            optionsBox->Scroll( _y );
        }

        void UpdateOptions()
        {
            Update();

            if( isSelected )
            {
                optionsBox->Update();

                optionsBox->CheckClicked( newIndex );
                if( (newIndex != -1) && (newIndex != index) )
                {
                    index = newIndex;

                    settingsFile->data[category][name]["index"] = index;
                    settingsFile->isWriteData = true;
                }
            }

            SwitchSelected();
        }

    };

}

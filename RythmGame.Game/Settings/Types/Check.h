#pragma once

#include <string>

#include "../SettingBox.h"

#include "../../../RythmGame.Graphics/Settings/CheckBox/CheckBox.h"

using namespace RythmGame::Graphics::Settings;

namespace RythmGame::Game::Settings
{

    class Check : public SettingBox
    {
        bool value;

        CheckBox *checkBox;

    public:
        Check( std::string _category, std::string _name, float _y ) :
            SettingBox(
                _category,
                _name,
                _y
            )
        {
            value = settingsFile->data[_category][_name]["value"];
        }

        void InitCheck()
        {
            Init();
            checkBox = new CheckBox( posY, value );
        }

        void ScrollCheck( float _y )
        {
            Scroll( _y );
            checkBox->Scroll( _y );
        }

        void UpdateCheck()
        {
            Update();

            checkBox->Update();
            value = checkBox->GetIsOn();

            if( settingsFile->data[category][name]["value"] != value )
            {
                settingsFile->data[category][name]["value"] = value;
                settingsFile->isWriteData = true;
            }
        }

        bool GetValue() { return value; }

    };

}

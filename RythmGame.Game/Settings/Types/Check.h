#pragma once

#include <string>

#include "../SettingBox.h"

namespace RythmGame::Game::Settings
{

    class Check : public SettingBox
    {
        bool value;

    public:
        Check( std::string _name, int _posY, bool _value ) :
            SettingBox(
                _name,
                _posY
            )
        {
            value = _value;
        }

        void InitCheck()
        {
            Init();
        }

        void UpdateCheck()
        {
            Update();
        }

        void DrawCheck()
        {
            DrawBackgroundBox();
            if( isSelected )
            {
            }
            else
            {
                DrawText();
            }
        }

        bool GetValue() { return value; }

    };

}
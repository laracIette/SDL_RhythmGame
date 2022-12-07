#pragma once

#include <string>

#include "../SettingBox.h"

namespace RythmGame::Game::Settings
{

    class Check : public SettingBox
    {
        bool value;

    public:
        Check( std::string _name, float _y, bool _value ) :
            SettingBox(
                _name,
                _y
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

        bool GetValue() { return value; }

    };

}

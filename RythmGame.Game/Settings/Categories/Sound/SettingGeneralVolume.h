#pragma once

#include "../../SettingsFile.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingGeneralVolume
    {
        int volume;

    public:
        SettingGeneralVolume()
        {
            volume = settingsFile->data["Sound"]["GeneralVolume"]["value"];
        }
        ~SettingGeneralVolume() {}

        int GetGeneralVolume() { return volume; }
    };


}

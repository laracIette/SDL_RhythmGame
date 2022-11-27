#pragma once

#include "../../SettingsFile.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingMusicVolume
    {
        int volume;

    public:
        SettingMusicVolume()
        {
            volume = settingsFile->data["Sound"]["MusicVolume"]["value"];
        }
        ~SettingMusicVolume() {}

        int GetMusicVolume() { return volume; }
    };


}

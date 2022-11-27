#pragma once

#include "../../SettingsFile.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingHitSoundsVolume
    {
        int volume;

    public:
        SettingHitSoundsVolume()
        {
            volume = settingsFile->data["Sound"]["HitSoundsVolume"]["value"];
        }
        ~SettingHitSoundsVolume() {}

        int GetHitSoundsVolume() { return volume; }
    };


}

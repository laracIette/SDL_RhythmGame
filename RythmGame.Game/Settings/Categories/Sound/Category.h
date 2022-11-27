#pragma once

#include "SettingGeneralVolume.h"
#include "SettingMusicVolume.h"
#include "SettingHitSoundsVolume.h"

namespace RythmGame::Game::Settings::Sound
{

    class Category : public SettingGeneralVolume, public SettingMusicVolume, public SettingHitSoundsVolume
    {

    public:
        Category() : SettingGeneralVolume(), SettingMusicVolume(), SettingHitSoundsVolume()
        {
        }

    };


}
#pragma once

#include "../../Types/Check.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingSkinHitSounds : public Check
    {

    public:
        SettingSkinHitSounds( float _y ) :
            Check(
                "Enable Skin HitSounds",
                _y,
                settingsFile->data["Sound"]["SkinHitSounds"]["value"]
            )
        {
        }

        void InitSkinHitSounds()
        {
            InitCheck();
        }

        void ScrollSkinHitSounds( float _y )
        {
            Scroll( _y );
        }

        void UpdateSkinHitSounds()
        {
            UpdateCheck();
        }

        bool GetSkinHitSounds() { return GetValue(); }
    };


}
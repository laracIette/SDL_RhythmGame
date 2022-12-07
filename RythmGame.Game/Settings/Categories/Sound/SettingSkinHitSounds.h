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
                "Sound",
                "SkinHitSounds",
                _y
            )
        {
        }

        void InitSkinHitSounds()
        {
            InitCheck();
        }

        void ScrollSkinHitSounds( float _y )
        {
            ScrollCheck( _y );
        }

        void UpdateSkinHitSounds()
        {
            UpdateCheck();
        }

        bool GetSkinHitSounds() { return GetValue(); }
    };


}
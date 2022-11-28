#pragma once

#include "../../Types/Check.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingSkinHitSounds : public Check
    {

    public:
        SettingSkinHitSounds( int _posY ) :
            Check(
                "Enable Skin HitSounds",
                _posY,
                settingsFile->data["Sound"]["SkinHitSounds"]["value"]
            )
        {
        }

        void InitSkinHitSounds()
        {
            InitCheck();
        }

        void ScrollSkinHitSounds( int _posY )
        {
            Scroll( _posY );
        }

        void UpdateSkinHitSounds()
        {
            UpdateCheck();
        }

        void DrawSkinHitSounds()
        {
            DrawCheck();
        }

        bool GetSkinHitSounds() { return GetValue(); }
    };


}
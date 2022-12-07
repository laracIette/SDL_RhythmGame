#pragma once

#include "../CategoryTemplate.h"

#include "SettingGeneralVolume.h"
#include "SettingMusicVolume.h"
#include "SettingHitSoundsVolume.h"
#include "SettingSkinHitSounds.h"

namespace RythmGame::Game::Settings::Sound
{

    class Category :
        public CategoryTemplate,
        public SettingGeneralVolume,
        public SettingMusicVolume,
        public SettingHitSoundsVolume,
        public SettingSkinHitSounds
    {

    public:
        Category( float _y ) :
            CategoryTemplate( "Sound", _y, GetSoundHeight() ),
            SettingGeneralVolume(   _y+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE ),
            SettingMusicVolume(     _y+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE ),
            SettingHitSoundsVolume( _y+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE*2 ),
            SettingSkinHitSounds(   _y+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE*3 )
        {
        }

        void InitSound()
        {
            InitCategoryName();
            InitGeneralVolume();
            InitMusicVolume();
            InitHitSoundsVolume();
            InitSkinHitSounds();
        }

        void ScrollSound( float _y )
        {
            ScrollCategoryName( _y );
            ScrollGeneralVolume( _y );
            ScrollMusicVolume( _y );
            ScrollHitSoundsVolume( _y );
            ScrollSkinHitSounds( _y );
        }

        void UpdateSound()
        {
            UpdateGeneralVolume();
            UpdateMusicVolume();
            UpdateHitSoundsVolume();
            UpdateSkinHitSounds();
        }

        int GetSoundHeight() { return FONT_SIZE_CATEGORY_TITLE_WITH_SPACE + FONT_SIZE_OPTION_WITH_SPACE*4; }

    };


}
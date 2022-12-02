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
        Category( int _posY ) :
            CategoryTemplate( "Sound", _posY, GetSoundHeight() ),
            SettingGeneralVolume(   _posY+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE ),
            SettingMusicVolume(     _posY+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE ),
            SettingHitSoundsVolume( _posY+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE*2 ),
            SettingSkinHitSounds(   _posY+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE*3 )
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

        void ScrollSound( int _posY )
        {
            ScrollCategoryName( _posY );
            ScrollGeneralVolume( _posY );
            ScrollMusicVolume( _posY );
            ScrollHitSoundsVolume( _posY );
            ScrollSkinHitSounds( _posY );
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
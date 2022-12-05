#pragma once

#include "../CategoryTemplate.h"

#include "SettingDimension.h"
#include "SettingFPS.h"
#include "SettingZoom.h"

namespace RythmGame::Game::Settings::Video
{

    class Category :
        public CategoryTemplate,
        public SettingDimension,
        public SettingFPS,
        public SettingZoom
    {

    public:
        Category( int _posY ) :
            CategoryTemplate( "Video", _posY, GetVideoHeight() ),
            SettingDimension( _posY + FONT_SIZE_CATEGORY_TITLE_WITH_SPACE ),
            SettingFPS(       _posY + FONT_SIZE_CATEGORY_TITLE_WITH_SPACE + FONT_SIZE_OPTION_WITH_SPACE ),
            SettingZoom(      _posY + FONT_SIZE_CATEGORY_TITLE_WITH_SPACE + FONT_SIZE_OPTION_WITH_SPACE*2 )
        {
        }

        void InitVideo()
        {
            InitCategoryName();
            InitDimension();
            InitFPS();
            InitZoom();
        }

        void ScrollVideo( int _posY )
        {
            ScrollCategoryName( _posY );
            ScrollDimension( _posY );
            ScrollFPS( _posY );
            ScrollZoom( _posY );
        }

        void UpdateVideo()
        {
            UpdateDimension();
            UpdateFPS();
            UpdateZoom();
        }

        int GetVideoHeight() { return FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE*3; }

    };


}
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
        Category( float _y ) :
            CategoryTemplate( "Video", _y, GetVideoHeight() ),
            SettingDimension( _y + FONT_SIZE_CATEGORY_TITLE_WITH_SPACE ),
            SettingFPS(       _y + FONT_SIZE_CATEGORY_TITLE_WITH_SPACE + FONT_SIZE_OPTION_WITH_SPACE ),
            SettingZoom(      _y + FONT_SIZE_CATEGORY_TITLE_WITH_SPACE + FONT_SIZE_OPTION_WITH_SPACE*2 )
        {
        }

        void InitVideo()
        {
            InitCategoryName();
            InitDimension();
            InitFPS();
            InitZoom();
        }

        void ScrollVideo( float _y )
        {
            ScrollCategoryName( _y );
            ScrollDimension( _y );
            ScrollFPS( _y );
            ScrollZoom( _y );
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
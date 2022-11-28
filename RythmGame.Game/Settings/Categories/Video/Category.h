#pragma once

#include "../CategoryTemplate.h"

#include "SettingDimension.h"
#include "SettingFPS.h"

namespace RythmGame::Game::Settings::Video
{

    class Category :
        public CategoryTemplate,
        public SettingDimension,
        public SettingFPS
    {

    public:
        Category( int _posY ) :
            CategoryTemplate( "Video", _posY, GetVideoHeight() ),
            SettingDimension( _posY+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE ),
            SettingFPS(       _posY+FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE )
        {
        }

        void InitVideo()
        {
            InitCategoryName();
            InitDimension();
            InitFPS();
        }

        void ScrollVideo( int _posY )
        {
            ScrollCategoryName( _posY );
            ScrollDimension( _posY );
            ScrollFPS( _posY );
        }

        void UpdateVideo()
        {
            UpdateDimension();
            UpdateFPS();
        }

        void DrawVideo()
        {
            DrawCategoryName();
            DrawDimension();
            DrawFPS();
        }

        int GetVideoHeight() { return FONT_SIZE_CATEGORY_TITLE_WITH_SPACE+FONT_SIZE_OPTION_WITH_SPACE*2; }

    };


}
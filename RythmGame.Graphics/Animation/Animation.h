#pragma once

#include <filesystem>
#include <string>
#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include <vector>
#include <chrono>

#include "../../RythmGame.Game/Utils/Point.h"
#include "../../RythmGame.Game/Utils/Time.h"

#include "../Image/Image.h"


using namespace RythmGame::Game::Utils;
using namespace RythmGame::Graphics;


namespace RythmGame::Graphics
{

    class Animation
    {
        std::vector<Image *> images;
        int index;
        std::chrono::high_resolution_clock::time_point lastImageTime;

    public:
        Animation( std::string path, Rect dest );
        ~Animation();

        void Draw();

        float X();
        float Y();
        float W();
        float H();

        void SetX( float x );
        void SetY( float y );
        void SetW( float w );
        void SetH( float h );
    };

}
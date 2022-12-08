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

    template<typename T>
    class Animation
    {
        std::vector<Image *> images;
        int index;
        std::chrono::high_resolution_clock::time_point lastImageTime;

    public:
        Animation( std::string _path, Rect _dest, int _type, int _priority );
        ~Animation();

        void UpdateAnimation();

        float X(){ return images[0]->X(); }
        float Y(){ return images[0]->Y(); }
        float W(){ return images[0]->W(); }
        float H(){ return images[0]->H(); }

        void SetX( float _x );
        void SetY( float _y );
        void SetW( float _w );
        void SetH( float _h );
    };

}

#include "Animation.cpp"
#pragma once

#include <string>
#include "../inc/SDL-release-2.24.0/include/SDL.h"

#include "../RythmGame.Game/Utils/Point.h"
#include "../RythmGame.Game/Utils/Metrics.h"

#include "Image/Positions/ImageTopLeft.h"
#include "TextureManager/TextureManager.h"

namespace RythmGame::Graphics
{

    class Background : public ImageTopLeft
    {

    public:
    /**
        Background inherits from Image
    */
        Background( std::string _path, int _type, int _priority = 9 ) :
            ImageTopLeft(
                _path,
                {0, 0, 1920, 1080},
                _type,
                _priority
            )
        {}
    };


}
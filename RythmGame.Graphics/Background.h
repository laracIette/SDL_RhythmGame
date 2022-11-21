#pragma once

#include <string>
#include <SDL.h>

#include "../RythmGame.Game/Utils/Point.h"
#include "../RythmGame.Game/Utils/Metrics.h"

#include "Image/Image.h"
#include "TextureManager/TextureManager.h"

namespace RythmGame::Graphics
{

    class Background : public Image
    {

    public:
    /*
        Backgorund inherits from Image
    */
        Background( std::string path )
         : Image(
            path,
            getRectPointer(1920/2, 1080/2, 1920, 1080) )
        {}
    };


}
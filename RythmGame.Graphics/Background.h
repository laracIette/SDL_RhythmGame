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
        Background( std::string path, SDL_Rect src )
         : Image(
            path,
            src,
            {1920/2, 1080/2, 1920, 1080} )
        {}
    };


}
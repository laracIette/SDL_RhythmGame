#pragma once

#include <SDL.h>
#include <map>
#include <string>

#include "TextureManager/TextureManager.h"

namespace RythmGame::Graphics
{
    class ImageManager
    {

    public:
        std::map<std::string, SDL_Texture *> imagesTextureMap;

        ImageManager() {}
        ~ImageManager() {}

    };


    extern ImageManager imageManager;
}
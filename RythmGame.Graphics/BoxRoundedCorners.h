#pragma once

#include "../inc/SDL-release-2.24.0/include/SDL.h"
#include <iostream>

#include "../RythmGame.Game/Utils/GameSettings.h"

#include "TextureManager/TextureManager.h"

#include "Renderable.h"

#include "RenderQueue/RenderQueue.h"

#include "../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Graphics
{

    class BoxRoundedCorners : public Renderable
    {
        SDL_Texture *corner;
        Rect         dest;
        float        size;
        RGB          color;

    public:
        BoxRoundedCorners( Rect _dest, int _type, int _priority, RGB _color = White, const char *_path = "assets/UI/RoundedCorner.png" )
        {
            corner = TextureManager::LoadTexture( _path );

            dest = _dest;

            color = _color;

            size = lowest( dest.w, dest.h )/5;

            if( size > 25 )
            {
                size = 25;
            }

            renderQueue->AddQueue( this, _type, _priority );
        }
        ~BoxRoundedCorners() {}

        void SetY( float _y )
        {
            dest.y = _y;
        }

        void Draw()
        {
            Rect  rsDest{ resize(dest) };
            float rsSize{ resize(size) };

            Rect tempDest{ rsDest };

            tempDest.w = tempDest.h = rsSize;
            SDL_RenderCopyEx( window->renderer, corner, NULL,  getPointer(getSDLRect(tempDest)), 0, NULL, SDL_FLIP_NONE );

            tempDest.x = rsDest.x + rsDest.w - rsSize;
            SDL_RenderCopyEx( window->renderer, corner, NULL,  getPointer(getSDLRect(tempDest)), 0, NULL, SDL_FLIP_HORIZONTAL );

            tempDest.x = rsDest.x;
            tempDest.y = rsDest.y + rsDest.h - rsSize;
            SDL_RenderCopyEx( window->renderer, corner, NULL,  getPointer(getSDLRect(tempDest)), 0, NULL, SDL_FLIP_VERTICAL );

            tempDest.x = rsDest.x + rsDest.w - rsSize;
            tempDest.y = rsDest.y + rsDest.h - rsSize;
            SDL_RenderCopyEx( window->renderer, corner, NULL,  getPointer(getSDLRect(tempDest)), 0, NULL, (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL) );

            window->FillRectangle( {dest.x, dest.y+size, dest.w, dest.h-size*2}, color );

            window->FillRectangle( {dest.x+size, dest.y, dest.w-size*2, size}, color );

            window->FillRectangle( {dest.x+size, dest.y+dest.h-size, dest.w-size*2, size}, color );
        }
    };

}
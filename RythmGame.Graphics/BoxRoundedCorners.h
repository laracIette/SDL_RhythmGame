#pragma once

#include "../inc/SDL-release-2.24.0/include/SDL.h"
#include <iostream>

#include "../RythmGame.Game/Utils/GameSettings.h"

#include "TextureManager/TextureManager.h"

#include "RenderObject.h"

#include "RenderQueue/RenderQueue.h"

#include "../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Graphics
{

    class BoxRoundedCorners : public RenderObject
    {
        SDL_Texture *corner;
        SDL_Rect     dest;
        int          size;
        RGB          color;

    public:
    /**
     * RESIZE RECT BEFORE FUNCTION CALL
     */
        BoxRoundedCorners( SDL_Rect _dest, int _type, int _priority, RGB _color = White, const char *_path = "assets/UI/RoundedCorner.png" )
        {
            corner = TextureManager::LoadTexture( _path );

            dest = _dest;

            color = _color;

            size = lowest( dest.w, dest.h )/5;

            if( size > resize( 25 ) )
            {
                size = resize( 25 );
            }

            renderQueue->AddQueue( this, _type, _priority );
        }
        ~BoxRoundedCorners() {}

        void SetY( int _posY )
        {
            dest.y = resize( _posY );
        }

        void Draw()
        {
            SDL_Rect tempDest = dest;

            tempDest.w = tempDest.h = size;
            SDL_RenderCopyEx( window->renderer, corner, NULL,  &tempDest, 0, NULL, SDL_FLIP_NONE );

            tempDest.x = dest.x + dest.w - size;
            SDL_RenderCopyEx( window->renderer, corner, NULL,  &tempDest, 0, NULL, SDL_FLIP_HORIZONTAL );

            tempDest.x = dest.x;
            tempDest.y = dest.y + dest.h - size;
            SDL_RenderCopyEx( window->renderer, corner, NULL,  &tempDest, 0, NULL, SDL_FLIP_VERTICAL );

            tempDest.x = dest.x + dest.w - size;
            tempDest.y = dest.y + dest.h - size;
            SDL_RenderCopyEx( window->renderer, corner, NULL,  &tempDest, 0, NULL, (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL) );

            window->FillRectangle( {dest.x, dest.y+size, dest.w, dest.h-size*2}, color );

            window->FillRectangle( {dest.x+size, dest.y, dest.w-size*2, size}, color );

            window->FillRectangle( {dest.x+size, dest.y+dest.h-size, dest.w-size*2, size}, color );
        }
    };

}
#pragma once

#include <SDL.h>
#include <iostream>

#include "../RythmGame.Game/Utils/GameSettings.h"

#include "TextureManager/TextureManager.h"

#include "../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Graphics
{

    class BoxRoundedCorners
    {
        SDL_Texture *corner;
        SDL_Rect     dest, rectangleDest;
        int size;

    public:
        BoxRoundedCorners( SDL_Rect dest )
        {
            corner = TextureManager::LoadTexture( "assets/UI/RoundedCorner.png" );

            this->dest.x = resize( dest.x );
            this->dest.y = resize( dest.y );
            this->dest.w = resize( dest.w );
            this->dest.h = resize( dest.h );

            size = lowest( this->dest.w, this->dest.h )/10;
            if( size > resize( 25 ) ) size = resize( 25 );
        }
        ~BoxRoundedCorners() {}

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

            rectangleDest.x = dest.x;
            rectangleDest.y = dest.y+size;
            rectangleDest.w = dest.w;
            rectangleDest.h = dest.h-size*2;
            window->FillRectangle( rectangleDest, White );

            rectangleDest.x = dest.x+size;
            rectangleDest.y = dest.y;
            rectangleDest.w = dest.w-size*2;
            rectangleDest.h = size;
            window->FillRectangle( rectangleDest, White );

            rectangleDest.x = dest.x+size;
            rectangleDest.y = dest.y+dest.h-size;
            rectangleDest.w = dest.w-size*2;
            rectangleDest.h = size;
            window->FillRectangle( rectangleDest, White );
        }
    };

}
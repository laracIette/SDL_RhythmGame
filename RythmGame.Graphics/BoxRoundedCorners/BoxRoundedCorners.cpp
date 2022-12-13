#include "BoxRoundedCorners.h"

namespace RythmGame::Graphics
{

    BoxRoundedCorners::~BoxRoundedCorners()
    {
    }

    void BoxRoundedCorners::SetY( float _y )
    {
        dest.y = _y;
    }

    void BoxRoundedCorners::Draw()
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

    bool BoxRoundedCorners::IsNotHooverLeftClicked()
    {
        return (!inputManager->MouseInRect( dest ) && inputManager->LeftClickedNoLock());
    }

}
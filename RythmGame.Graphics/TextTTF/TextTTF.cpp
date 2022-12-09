#include "TextTTF.h"

namespace RythmGame::Graphics
{

    TextTTF::TextTTF( std::string _text, TTF_Font *_font, float _x, float _y, int _type, int _priority )
    {
        TTF_SizeText( _font, _text.c_str(), &dest.w, &dest.h );
        dest.w = unsize(dest.w);
        dest.h = unsize(dest.h);
        dest.x = _x;
        dest.y = _y;

        SDL_Surface *tempSurface = TTF_RenderText_Blended( _font, _text.c_str(), {255, 255, 255} );

        textTexture = SDL_CreateTextureFromSurface( window->renderer, tempSurface );
        if( !textTexture )
        {
            logFile->Write( "Error : creating text texture '" + _text + "'" + SDL_GetError() );
        }

        SDL_FreeSurface( tempSurface );

        renderQueue->AddQueue( this, _type, _priority );
    }

    TextTTF::~TextTTF()
    {
    }

    void TextTTF::Update( float _y )
    {
        dest.y = _y;
        Hoover();
    }


    void TextTTF::Draw()
    {
        window->DrawBox( getRect(dest), Red );
        SDL_RenderCopy( window->renderer, textTexture, NULL, getPointer<SDL_Rect>({resize(dest.x), resize(dest.y), resize(dest.w), resize(dest.h)}) );
    }

    void TextTTF::Hoover()
    {
        isHoover = false;

        if( inputManager->MouseInRect( (float)dest.x, (float)dest.y, (float)dest.w, (float)dest.h ) )
        {
            isHoover = true;
        }
    }

    bool TextTTF::IsHooverLeftClicked()
    {
        return (isHoover && inputManager->LeftClickedNoLock());
    }
    bool TextTTF::IsHooverRightClicked()
    {
        return (isHoover && inputManager->RightClickedNoLock());
    }
    bool TextTTF::IsNotHooverLeftClicked()
    {
        return (!isHoover && inputManager->LeftClickedNoLock());
    }
    bool TextTTF::IsNotHooverRightClicked()
    {
        return (!isHoover && inputManager->RightClickedNoLock());
    }
}

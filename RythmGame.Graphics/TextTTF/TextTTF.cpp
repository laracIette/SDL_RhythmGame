#include "TextTTF.h"

namespace RythmGame::Graphics
{

    TextTTF::TextTTF( std::string _text, TTF_Font *_font, int _posX, int _posY )
    {
        TTF_SizeText( _font, _text.c_str(), &dest.w, &dest.h );
        dest.x = resize( _posX );
        dest.y = resize( _posY );

        SDL_Surface *tempSurface = TTF_RenderText_Blended( _font, _text.c_str(), {255, 255, 255} );

        textTexture = SDL_CreateTextureFromSurface( window->renderer, tempSurface );
        if( !textTexture )
        {
            std::cout << "error creating text texture '" << _text << "'" << SDL_GetError() << std::endl;
        }

        SDL_FreeSurface( tempSurface );
    }

    TextTTF::~TextTTF()
    {
    }

    void TextTTF::Update( int _posY )
    {
        dest.y = resize( _posY );
        Hoover();
    }


    void TextTTF::Draw()
    {
        window->DrawBox( dest, Red );
        SDL_RenderCopy( window->renderer, textTexture, NULL, &dest );
    }

    void TextTTF::Hoover()
    {
        isHoover = false;

        if( inputManager.MouseInRect( dest.x, dest.y, dest.w, dest.h ) )
        {
            isHoover = true;
        }
    }

    bool TextTTF::IsHooverLeftClicked()
    {
        return (isHoover && inputManager.LeftClickedNoLock());
    }
    bool TextTTF::IsHooverRightClicked()
    {
        return (isHoover && inputManager.RightClickedNoLock());
    }
    bool TextTTF::IsNotHooverLeftClicked()
    {
        return (!isHoover && inputManager.LeftClickedNoLock());
    }
    bool TextTTF::IsNotHooverRightClicked()
    {
        return (!isHoover && inputManager.RightClickedNoLock());
    }
}

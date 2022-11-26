#include "TextTTF.h"

namespace RythmGame::Graphics
{

    TextTTF::TextTTF( std::string text, TTF_Font *font, int posX, int posY )
    {
        TTF_SizeText( font, text.c_str(), &dest.w, &dest.h );
        dest.x = resize( posX );
        dest.y = resize( posY );

        SDL_Surface *tempSurface = TTF_RenderText_Blended( font, text.c_str(), {255, 255, 255} );

        textTexture = SDL_CreateTextureFromSurface( window->renderer, tempSurface );
        if( !textTexture )
        {
            std::cout << "error creating text texture '" << text << "'" << SDL_GetError() << std::endl;
        }

        SDL_FreeSurface( tempSurface );

    }

    TextTTF::~TextTTF()
    {
    }

    void TextTTF::Update( int posY )
    {
        dest.y = resize( posY );
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

    bool TextTTF::IsLeftClicked()
    {
        return (isHoover && inputManager.LeftClickedNoLock());
    }
    bool TextTTF::IsRightClicked()
    {
        return (isHoover && inputManager.RightClickedNoLock());
    }
}

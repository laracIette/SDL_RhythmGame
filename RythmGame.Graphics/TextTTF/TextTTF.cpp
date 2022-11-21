#include "TextTTF.h"

namespace RythmGame::Graphics
{

    TextTTF::TextTTF( const char *text, TTF_Font *font, int posX, int posY )
    {
        TTF_SizeText( font, text, (int *)&dest->w, (int *)&dest->h );
        dest->x = posX;
        dest->y = posY;

        SDL_Surface *tempSurface = TTF_RenderText_Blended( font, text, {255, 255, 255} );

        textTexture = GPU_CopyImageFromSurface( tempSurface );
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
        dest->y = posY;
    }

    void TextTTF::Draw()
    {
        GPU_BlitRect( textTexture, NULL, window->renderer, dest );
    }

}

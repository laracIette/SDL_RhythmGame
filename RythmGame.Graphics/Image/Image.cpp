#include "Image.h"

namespace RythmGame::Graphics
{
    Image::Image( std::string path, SDL_Rect src, Rect dest )
    {
        tex = TextureManager::LoadTexture( const_cast<char *>( path.c_str() ) );
        this->src = src;
        this->dest = dest;

        posX = 0;
        posY = 0;
        posW = 0;
        posH = 0;
    }

    Image::~Image()
    {
    }

    void Image::Draw()
    {
        Draw( dest );
    }
    void Image::Draw( Rect dest )
    {
        posX = Resize( dest.x - dest.w/2 );
        posY = Resize( dest.y - dest.h/2 );
        posW = Resize( dest.w );
        posH = Resize( dest.h );

        TextureManager::DrawTexture(
            tex,
            src,
            {(int)posX, (int)posY, (int)posW, (int)posH}
        );
    }
    template<typename T>
    float Image::Resize( T n )
    {
        return (float)n / 1920 * (float)WIDTH;
    }

}
#include "Image.h"

Image::Image( std::string path, SDL_Rect src, Rect dest )
{

    const char *newPath = const_cast<char *>( path.c_str() );

    tex = TextureManager::LoadTexture( const_cast<char *>( path.c_str() ) );
    this->src = src;
    this->dest = dest;
}

Image::~Image()
{
}

void Image::Draw()
{
    TextureManager::DrawTexture(
        tex,
        src,
        {(int)(dest.x-dest.w/2), (int)(dest.y-dest.h/2), (int)(dest.w), (int)(dest.h)}
    );
}

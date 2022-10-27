#include "Image.h"

Image::Image( const char *path, SDL_Rect src, Rect dest )
{
    tex = TextureManager::LoadTexture( path );
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

#include "Image.h"

namespace RythmGame::Graphics
{
    Image::Image( std::string path, Rect dest )
    {
        tex = TextureManager::LoadTexture( const_cast<char *>( path.c_str() ) );
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
            {(int)posX, (int)posY, (int)posW, (int)posH}
        );
    }
    template<typename T>
    float Image::Resize( T n )
    {
        return (float)n / 1920 * (float)WIDTH;
    }

    void Image::Hoover()
    {
        isHoover = false;

        if( (inputManager.mouse.pos.x > Resize( dest.x - dest.w/2 )) && (inputManager.mouse.pos.x < Resize( dest.x + dest.w/2 ))
         && (inputManager.mouse.pos.y > Resize( dest.y - dest.h/2 )) && (inputManager.mouse.pos.y < Resize( dest.y + dest.h/2 )) )
        {
            isHoover = true;
        }

    }

    bool Image::IsHoover()
    {
        return isHoover;
    }

    bool Image::IsLeftClicked()
    {
        bool ret{ isHoover && inputManager.LeftClickedNoLock() };

        if( inputManager.LeftClicked() )
        {
            inputManager.SetButtonLock( inputManager.mouse.Left, true );
        }

        return ret;
    }
    bool Image::IsRightClicked()
    {
        bool ret{ isHoover && inputManager.RightClickedNoLock() };

        if( inputManager.RightClicked() )
        {
            inputManager.SetButtonLock( inputManager.mouse.Right, true );
        }

        return ret;
    }
}
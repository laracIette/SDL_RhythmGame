#include "Image.h"

namespace RythmGame::Graphics
{

    Image::Image( std::string path, Rect dest, int position )
    {
        tex = TextureManager::LoadTexture( const_cast<char *>( path.c_str() ) );
        this->dest = dest;

        posX = 0;
        posY = 0;
        posW = 0;
        posH = 0;

        this->position = position;

        zoom = 1.0f;
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
        switch( position )
        {
        case Center:
            posX = resize( dest.x - dest.w*zoom/2 );
            posY = resize( dest.y - dest.h*zoom/2 );
            break;

        case TopLeft:
            posX = resize( dest.x );
            posY = resize( dest.y );
            break;

        case TopRight:
            posX = resize( dest.x - dest.w*zoom );
            posY = resize( dest.y );
            break;

        case BottomLeft:
            posX = resize( dest.x );
            posY = resize( dest.y - dest.h*zoom );
            break;

        case BottomRight:
            posX = resize( dest.x - dest.w*zoom );
            posY = resize( dest.y - dest.h*zoom );
            break;

        default:
            break;
        }

        posW = resize( dest.w*zoom );
        posH = resize( dest.h*zoom );

        TextureManager::DrawTexture(
            tex,
            {(int)posX, (int)posY, (int)posW, (int)posH}
        );
    }

    void Image::Hoover()
    {
        isHoover = false;

        switch( position )
        {
        case Center:
            if( inputManager.MouseInRect( resize( dest.x - dest.w*zoom/2 ), resize( dest.y - dest.h*zoom/2 ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        case TopLeft:
            if( inputManager.MouseInRect( resize( dest.x ), resize( dest.y ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        case TopRight:
            if( inputManager.MouseInRect( resize( dest.x - dest.w*zoom ), resize( dest.y ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        case BottomLeft:
            if( inputManager.MouseInRect( resize( dest.x ), resize( dest.y - dest.h*zoom ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        case BottomRight:
            if( inputManager.MouseInRect( resize( dest.x - dest.w*zoom ), resize( dest.y - dest.h*zoom ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        default:
            break;
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
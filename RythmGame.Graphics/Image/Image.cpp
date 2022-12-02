#include "Image.h"

namespace RythmGame::Graphics
{

    Image::Image( std::string _path, Rect _dest, int _type, int _priority, int _position )
    {
        if( imageManager->imagesTextureMap.count( _path ) )
        {
            tex = imageManager->imagesTextureMap[_path];
        }
        else
        {
            imageManager->imagesTextureMap[_path] = TextureManager::LoadTexture( const_cast<char *>( _path.c_str() ) );
            tex = imageManager->imagesTextureMap[_path];
        }

        dest = _dest;

        posX = 0;
        posY = 0;
        posW = 0;
        posH = 0;

        position = _position;

        zoom = 1.0f;

        if( _type == (RenderMapSelection | RenderGameplay) )
        {
            renderQueue->AddQueue( this, RenderMapSelection, _priority );
            renderQueue->AddQueue( this, RenderGameplay, _priority );
        }
        else
        {
            renderQueue->AddQueue( this, _type, _priority );
        }

    }

    Image::~Image()
    {
    }

    void Image::Draw()
    {
        Draw( dest );
    }

    void Image::Draw( Rect _dest )
    {
        switch( position )
        {
        case Center:
            posX = resize( _dest.x - _dest.w*zoom/2 );
            posY = resize( _dest.y - _dest.h*zoom/2 );
            break;

        case TopLeft:
            posX = resize( _dest.x );
            posY = resize( _dest.y );
            break;

        case TopRight:
            posX = resize( _dest.x - _dest.w*zoom );
            posY = resize( _dest.y );
            break;

        case BottomLeft:
            posX = resize( _dest.x );
            posY = resize( _dest.y - _dest.h*zoom );
            break;

        case BottomRight:
            posX = resize( _dest.x - _dest.w*zoom );
            posY = resize( _dest.y - _dest.h*zoom );
            break;

        default:
            break;
        }

        posW = resize( _dest.w*zoom );
        posH = resize( _dest.h*zoom );

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
            if( inputManager->MouseInRect( resize( dest.x - dest.w*zoom/2 ), resize( dest.y - dest.h*zoom/2 ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        case TopLeft:
            if( inputManager->MouseInRect( resize( dest.x ), resize( dest.y ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        case TopRight:
            if( inputManager->MouseInRect( resize( dest.x - dest.w*zoom ), resize( dest.y ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        case BottomLeft:
            if( inputManager->MouseInRect( resize( dest.x ), resize( dest.y - dest.h*zoom ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
            {
                isHoover = true;
            }
            break;

        case BottomRight:
            if( inputManager->MouseInRect( resize( dest.x - dest.w*zoom ), resize( dest.y - dest.h*zoom ), resize( dest.w*zoom ), resize( dest.h*zoom ) ) )
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
        return (isHoover && inputManager->LeftClickedNoLock());
    }
    bool Image::IsRightClicked()
    {
        return (isHoover && inputManager->RightClickedNoLock());
    }
}
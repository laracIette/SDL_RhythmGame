#include "Image.h"

namespace RythmGame::Graphics
{

    Image::Image( std::string _path, Rect _dest, int _type, int _priority )
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

        isHoover = false;
    }

    Image::~Image()
    {
    }

    void Image::Draw( Rect _dest )
    {
        TextureManager::DrawTexture( tex, _dest );
    }


    bool Image::IsHooverLeftClicked()
    {
        return (IsHoover() && inputManager->LeftClickedNoLock());
    }
    bool Image::IsHooverRightClicked()
    {
        return (IsHoover() && inputManager->RightClickedNoLock());
    }
}
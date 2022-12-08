#pragma once

#include <string>

#include "../Image.h"

namespace RythmGame::Graphics
{

    class ImageCenter : public Image
    {

    public:
        ImageCenter( std::string _path, Rect _dest, int _type, int _priority ) :
            Image(
                _path,
                _dest,
                _type,
                _priority
            )
        {}

        void Draw()
        {
            Image::Draw( {dest.x - dest.w*zoom/2, dest.y - dest.h*zoom/2, dest.w*zoom, dest.h*zoom} );
        }


        void Hoover()
        {
            if( inputManager->MouseInRect( dest.x - dest.w*zoom/2, dest.y - dest.h*zoom/2, dest.w*zoom, dest.h*zoom ) )
            {
                isHoover = true;
            }
            else
            {
                isHoover = false;
            }
        }

    };

}
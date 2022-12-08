#pragma once

#include "Animation.h"

namespace RythmGame::Graphics
{
    template<typename T>
    Animation<T>::Animation( std::string _path, Rect _dest, int _type, int _priority )
    {
        for( const auto &entry : std::filesystem::directory_iterator( _path ) )
        {
            if( CheckImageExists( entry.path() ) )
            {
                images.push_back(
                    new T(
                        entry.path(),
                        _dest,
                        _type,
                        _priority
                    )
                );
            }
        }

        index = 0;
        lastImageTime = currentTime;
    }
    template<typename T>
    Animation<T>::~Animation()
    {
    }

    template<typename T>
    void Animation<T>::UpdateAnimation()
    {
        images[index]->Show();

        if( getDuration<Milliseconds>(currentTime, lastImageTime) > 1000/FPS )
        {
            lastImageTime = currentTime;
            if( ++index >= images.size() ) index = 0;
        }
    }

    template<typename T>
    void Animation<T>::SetX( float _x )
    {
        for( Image *image : images )
        {
            image->SetX( _x );
        }
    }
    template<typename T>
    void Animation<T>::SetY( float _y )
    {
        for( Image *image : images )
        {
            image->SetY( _y );
        }
    }
    template<typename T>
    void Animation<T>::SetW( float _w )
    {
        for( Image *image : images )
        {
            image->SetW( _w );
        }
    }
    template<typename T>
    void Animation<T>::SetH( float _h )
    {
        for( Image *image : images )
        {
            image->SetH( _h );
        }
    }

}

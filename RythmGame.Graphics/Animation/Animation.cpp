#include "Animation.h"

namespace RythmGame::Graphics
{

    Animation::Animation( std::string _path, Rect _dest, int _type, int _priority )
    {
        for( const auto &entry : std::filesystem::directory_iterator( _path ) )
        {
            if( CheckImageExists( entry.path() ) )
            {
                images.push_back(
                    new Image(
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

    Animation::~Animation()
    {
    }


    void Animation::UpdateAnimation()
    {
        images[index]->Show();

        if( getDuration<Milliseconds>(currentTime, lastImageTime) > 1000/10 )
        {
            lastImageTime = currentTime;
            if( ++index >= images.size() ) index = 0;
        }
    }


    float Animation::X()
    {
        return images[0]->X();
    }
    float Animation::Y()
    {
        return images[0]->Y();
    }
    float Animation::W()
    {
        return images[0]->W();
    }
    float Animation::H()
    {
        return images[0]->H();
    }



    void Animation::SetX( float _x )
    {
        for( Image *image : images )
        {
            image->SetX( _x );
        }
    }
    void Animation::SetY( float _y )
    {
        for( Image *image : images )
        {
            image->SetY( _y );
        }
    }
    void Animation::SetW( float _w )
    {
        for( Image *image : images )
        {
            image->SetW( _w );
        }
    }
    void Animation::SetH( float _h )
    {
        for( Image *image : images )
        {
            image->SetH( _h );
        }
    }

}
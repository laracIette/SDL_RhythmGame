#include "Animation.h"

namespace RythmGame::Graphics
{

    Animation::Animation( std::string path, Rect dest )
    {
        for( const auto &entry : std::filesystem::directory_iterator( path ) )
        {
            if( CheckImageExists( entry.path() ) )
            {
                images.push_back(
                    new Image(
                        entry.path(),
                        dest
                    )
                );
            }
        }

        indice = 0;
        lastImageTime = currentTime;

    }

    Animation::~Animation()
    {
    }


    void Animation::Draw()
    {
        images[indice]->Draw();

        if( getDuration<Milliseconds>(currentTime, lastImageTime) > 1000/10 )
        {
            lastImageTime = currentTime;
            if( ++indice >= images.size() ) indice = 0;
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



    void Animation::SetX( float x )
    {
        for( Image *image : images )
        {
            image->SetX( x );
        }
    }
    void Animation::SetY( float y )
    {
        for( Image *image : images )
        {
            image->SetY( y );
        }
    }
    void Animation::SetW( float w )
    {
        for( Image *image : images )
        {
            image->SetW( w );
        }
    }
    void Animation::SetH( float h )
    {
        for( Image *image : images )
        {
            image->SetH( h );
        }
    }

}
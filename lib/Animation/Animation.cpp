#include "Animation.h"


Animation::Animation()
{
    images.push_back( new Image(
        "assets/Skins/BaseSkin/HitObjects/Notes/Note0.png",
        {0, 0, 2048, 2048},
        {0, 0, 50, 50}
    ) );
    images.push_back( new Image(
        "assets/Skins/BaseSkin/HitObjects/Notes/Note1.png",
        {0, 0, 50, 50},
        {0, 0, 50, 50}
    ) );

    indice = 0;
    timeSinceLastImage = currentTime;

}

Animation::~Animation()
{
}


void Animation::Draw()
{

    images[indice]->Draw();

    if( (currentTime - timeSinceLastImage) > 200 )
    {
        timeSinceLastImage = currentTime;
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
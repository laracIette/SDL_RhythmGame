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

    if( (currentTime - offsetTime - timeSinceLastImage) > 200 )
    {
        timeSinceLastImage = currentTime;
        if( ++indice >= images.size() ) indice = 0;
    }
}
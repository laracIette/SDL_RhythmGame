#ifndef RYTHMGAME_GRAPHICS_ANIMATION_H
#define RYTHMGAME_GRAPHICS_ANIMATION_H


#include "../../includes.h"

using namespace RythmGame::Game::Utils;


namespace RythmGame::Graphics
{

    class Animation
    {
        std::vector<Image *> images;
        unsigned int indice;
        unsigned int timeSinceLastImage;

    public:
        Animation( std::string path, SDL_Rect src, Rect dest );
        ~Animation();

        void Draw();

        float X();
        float Y();
        float W();
        float H();

        void SetX( float x );
        void SetY( float y );
        void SetW( float w );
        void SetH( float h );
    };

}

#endif // RYTHMGAME_GRAPHICS_ANIMATION_H
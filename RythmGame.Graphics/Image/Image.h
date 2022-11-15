#ifndef RYTHMGAME_GRAPHICS_IMAGE_H
#define RYTHMGAME_GRAPHICS_IMAGE_H


#include "../../includes.h"

using namespace RythmGame::Game::Utils;


namespace RythmGame::Graphics
{

// returns 1 if the path is ends with png
// else returns 0
    static bool CheckImageExists( std::string path )
    {
        if( (path[path.size()-3] != 'p') || (path[path.size()-2] != 'n') || (path[path.size()-1] != 'g') )
            return 0;

        return 1;
    }

    class Image
    {
        SDL_Texture *tex;
        SDL_Rect src;
        Rect dest;

    public:
        Image( std::string path, SDL_Rect src, Rect dest );
        ~Image();

        void Draw();
        void Draw( Rect dest );

        float X() { return dest.x; }
        float Y() { return dest.y; }
        float W() { return dest.w; }
        float H() { return dest.h; }

        void SetX( float x ) { dest.x = x; }
        void SetY( float y ) { dest.y = y; }
        void SetW( float w ) { dest.w = w; }
        void SetH( float h ) { dest.h = h; }
    };

}

#endif // RYTHMGAME_GRAPHICS_IMAGE_H
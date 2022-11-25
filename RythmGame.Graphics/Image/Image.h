#pragma once

#include <string>
#include <SDL.h>

#include "../../RythmGame.Game/Utils/Point.h"
#include "../../RythmGame.Game/Utils/GameSettings.h"

#include "../../RythmGame.Game/Events/InputManager.h"

#include "../TextureManager/TextureManager.h"

#include "../ImageManager.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;

namespace RythmGame::Graphics
{
    enum Positions {
        Center = 0,
        Top,
        Left,
        Right,
        Bottom,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

/**
 * \returns
 * true if the path ends with png
 * else false
 */
    static bool CheckImageExists( std::string path )
    {
        if( (path[path.size()-3] != 'p') || (path[path.size()-2] != 'n') || (path[path.size()-1] != 'g') )
            return 0;

        return 1;
    }

    class Image
    {
        float posX, posY, posW, posH;
        SDL_Texture *tex;
        int position;

    protected:
        Rect dest;
        bool isHoover;
        float zoom;

    public:
        Image( std::string path, Rect dest, int position = Center );
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

        Rect GetRect() { return dest; }

        void Hoover();
        bool IsHoover();

        bool IsLeftClicked();
        bool IsRightClicked();
    };

}
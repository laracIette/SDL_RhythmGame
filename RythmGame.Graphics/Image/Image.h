#pragma once

#include <string>
#include "../../inc/SDL-release-2.24.0/include/SDL.h"

#include "../../RythmGame.Game/Utils/Point.h"
#include "../../RythmGame.Game/Utils/GameSettings.h"

#include "../../RythmGame.Game/Events/InputManager.h"

#include "../TextureManager/TextureManager.h"

#include "../ImageManager.h"
#include "../RenderObject.h"

#include "../RenderQueue/RenderQueue.h"

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
 * \returns true if the path ends with png, else false.
 */
    static bool CheckImageExists( std::string _path )
    {
        if( (_path[_path.size()-3] != 'p') || (_path[_path.size()-2] != 'n') || (_path[_path.size()-1] != 'g') )
            return 0;

        return 1;
    }

    class Image : public RenderObject
    {
        float posX, posY, posW, posH;
        SDL_Texture *tex;
        int position;

    protected:
        Rect dest;
        bool isHoover;
        float zoom;

    public:
        Image( std::string _path, Rect _dest, int _type, int _priority, int _position = Center );
        ~Image();

        void Draw();
        void Draw( Rect _dest );

        float X() { return dest.x; }
        float Y() { return dest.y; }
        float W() { return dest.w; }
        float H() { return dest.h; }

        void SetX( float _x ) { dest.x = _x; }
        void SetY( float _y ) { dest.y = _y; }
        void SetW( float _w ) { dest.w = _w; }
        void SetH( float _h ) { dest.h = _h; }

        Rect GetRect() { return dest; }

        void Hoover();
        bool IsHoover();

        bool IsLeftClicked();
        bool IsRightClicked();
    };

}
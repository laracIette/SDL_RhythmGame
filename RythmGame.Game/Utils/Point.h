#ifndef RYTHMGAME_GAME_UTILS_POINT_H
#define RYTHMGAME_GAME_UTILS_POINT_H


#include "../../includes.h"


namespace RythmGame::Game::Utils
{
    template<typename T>
    struct vec2
    {
        T x, y;
    };

    struct RGB
    {
        unsigned char r, g, b;
    };

    struct Rect
    {
        float x, y, w, h;
    };

}
extern RythmGame::Game::Utils::vec2<int> mouse;

#endif // RYTHMGAME_GAME_UTILS_POINT_H
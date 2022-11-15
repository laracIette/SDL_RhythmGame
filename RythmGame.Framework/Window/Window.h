#ifndef RYTHMGAME_FRAMEWORK_WINDOW_H
#define RYTHMGAME_FRAMEWORK_WINDOW_H


#include "../../includes.h"

using namespace RythmGame::Game::Utils;

namespace RythmGame::Framework
{

    class Window
    {

    public:
        Window();
        ~Window();

        SDL_Window *window;
        SDL_Renderer *renderer;
    };

}

extern RythmGame::Framework::Window *window;


#endif // RYTHMGAME_FRAMEWORK_WINDOW_H
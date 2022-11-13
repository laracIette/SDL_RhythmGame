#pragma once

#include <SDL.h>

namespace RythmGame::Game::Events
{

    struct KeyboardEvents
    {
        static const int KEYS{ 38 };

        SDL_KeyCode keyCode[KEYS]{
            SDLK_0,
            SDLK_1,
            SDLK_2,
            SDLK_3,
            SDLK_4,
            SDLK_5,
            SDLK_6,
            SDLK_7,
            SDLK_8,
            SDLK_9,
            SDLK_SPACE,
            SDLK_a,
            SDLK_b,
            SDLK_c,
            SDLK_d,
            SDLK_e,
            SDLK_f,
            SDLK_g,
            SDLK_h,
            SDLK_i,
            SDLK_j,
            SDLK_k,
            SDLK_l,
            SDLK_m,
            SDLK_n,
            SDLK_o,
            SDLK_p,
            SDLK_q,
            SDLK_r,
            SDLK_s,
            SDLK_t,
            SDLK_u,
            SDLK_v,
            SDLK_w,
            SDLK_x,
            SDLK_y,
            SDLK_z,
            SDLK_ESCAPE
        };

        enum Keys {
            Space = 10,
            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            Escape
        };

        bool keyPressed[KEYS]{ false };

        bool keyLock[KEYS]{ false };
    };

}
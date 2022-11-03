#pragma once

#include "KeyboardEvents.h"
#include "MouseEvents.h"

struct Events
{
    KeyboardEvents keyboard;
    MouseEvents mouse;

    SDL_Event event;

    int HandleEvents()
    {
        SDL_GetMouseState( &mouse.pos.x, &mouse.pos.y );

        while( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
            case SDL_QUIT:
                return 1;;
                break;

            case SDL_KEYDOWN:
                for( int i{ 0 }; i < keyboard.KEYS; ++i )
                {
                    if( event.key.keysym.sym != keyboard.keyCode[i] ) continue;

                    keyboard.keyPressed[i] = true;
                    break;
                }
                break;

            case SDL_KEYUP:
                for( int i{ 0 }; i < keyboard.KEYS; ++i )
                {
                    if( event.key.keysym.sym != keyboard.keyCode[i] ) continue;

                    keyboard.keyPressed[i] = false;
                    SetKeyLock( i, false );
                    break;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                for( int i{ 0 }; i < mouse.BUTTONS; ++i )
                {
                    if( event.button.button != mouse.buttonCode[i] ) continue;

                    mouse.buttonClicked[i] = true;
                    break;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                for( int i{ 0 }; i < mouse.BUTTONS; ++i )
                {
                    if( event.button.button != mouse.buttonCode[i] ) continue;

                    mouse.buttonClicked[i] = false;
                    SetButtonLock( i, false );
                    break;
                }
                break;


            default:
                break;
            }
        }
        return 0;
    }

    bool Pressed( unsigned char key ) { return keyboard.keyPressed[key]; }
    bool Clicked( unsigned char button ) { return mouse.buttonClicked[button]; }

    bool KeyLock( unsigned char key ) { return keyboard.keyLock[key]; }
    bool ClicLock( unsigned char button ) { return mouse.buttonLock[button]; }

    void SetKeyLock( unsigned char key, bool lock ) { keyboard.keyLock[key] = lock; }
    void SetButtonLock( unsigned char button, bool lock ) { mouse.buttonLock[button] = lock; }
};

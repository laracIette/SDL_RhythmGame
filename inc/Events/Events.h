#pragma once

#include "KeyboardEvents.h"
#include "MouseEvents.h"

struct Events
{
    KeyboardEvents keyboard;
    MouseEvents mouse;

    SDL_Event event;

    int leftKey1{ keyboard.D };
    int leftKey2{ keyboard.F };
    int rightKey1{ keyboard.H };
    int rightKey2{ keyboard.J };

    int flipKey{ keyboard.Space };

    int HandleEvents()
    {
        SDL_GetMouseState( &mouse.pos.x, &mouse.pos.y );

        while( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
            case SDL_QUIT:
                return 1;

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


    bool Pressed( int key )    { return keyboard.keyPressed[key]; }
    bool Clicked( int button ) { return mouse.buttonClicked[button]; }

    bool KeyLock(    int key )    { return keyboard.keyLock[key]; }
    bool ButtonLock( int button ) { return mouse.buttonLock[button]; }

    void SetKeyLock(    int key,    bool lock ) { keyboard.keyLock[key]    = lock; }
    void SetButtonLock( int button, bool lock ) { mouse.buttonLock[button] = lock; }

    bool Right1Pressed() { return keyboard.keyPressed[rightKey1]; }
    bool Right2Pressed() { return keyboard.keyPressed[rightKey2]; }
    bool Left1Pressed()  { return keyboard.keyPressed[leftKey1]; }
    bool Left2Pressed()  { return keyboard.keyPressed[leftKey2]; }

    bool OnlyRight1Pressed() { return (Right1Pressed()  && !Right2Pressed()); }
    bool OnlyRight2Pressed() { return (!Right1Pressed() && Right2Pressed()); }

    bool OnlyLeft1Pressed() { return (Left1Pressed()  && !Left2Pressed()); }
    bool OnlyLeft2Pressed() { return (!Left1Pressed() && Left2Pressed()); }

    bool RightPressed() { return (Right1Pressed() || Right2Pressed()); }
    bool LeftPressed()  { return (Left1Pressed()  || Left2Pressed()); }

    bool OnlyRightPressed()    { return (RightPressed()  && !LeftPressed()); }
    bool OnlyLeftPressed()     { return (!RightPressed() && LeftPressed()); }
    bool RightAndLeftPressed() { return (RightPressed()  && LeftPressed()); }
    bool NothingPressed()      { return !(RightPressed() || LeftPressed()); }

};

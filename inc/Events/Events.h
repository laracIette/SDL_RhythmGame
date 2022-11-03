#pragma once

#include "KeyboardEvents.h"
#include "MouseEvents.h"

struct Events
{
    KeyboardEvents keyboard;
    MouseEvents mouse;

    bool Pressed( unsigned char key ) { return keyboard.keyPressed[key]; }
    bool Clicked( unsigned char button ) { return mouse.buttonClicked[button]; }

    bool KeyLock( unsigned char key ) { return keyboard.keyLock[key]; }
    bool ClicLock( unsigned char button ) { return mouse.buttonLock[button]; }

    void SetKeyLock( unsigned char key, bool lock ) { keyboard.keyLock[key] = lock; }
    void SetButtonLock( unsigned char button, bool lock ) { mouse.buttonLock[button] = lock; }
};

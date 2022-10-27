#include "Player.h"

void Player::Input()
{
    up   = false;
    down = true;

    upHit     = false;
    downHit   = false;

    if( events.buttonPressed[0] && events.buttonPressed[1] )
    {
        up   = false;
        down = false;

        upHit   = true;
        downHit = true;
    }

    else if( events.buttonPressed[0] )
    {
        up = true;

        upHit = true;
    }

    else if( events.buttonPressed[1] )
    {
        downHit = true;
    }


    if( up )
    {
        SetY( HEIGHT/2 - HEIGHT/10 );
    }
    else if( down )
    {
        SetY( HEIGHT/2 + HEIGHT/10 );
    }
    else
    {
        SetY( HEIGHT/2 );
    }


    if( upHit )   std::cout << "up\n";
    if( downHit ) std::cout << "down\n";
}
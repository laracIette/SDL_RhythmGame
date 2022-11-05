#include "Player.h"

void Player::Input()
{
    up   = false;
    down = true;

    upHit     = false;
    downHit   = false;

    if( events.Clicked( events.mouse.Left ) && events.Clicked( events.mouse.Right ) )
    {
        up   = false;
        down = false;

        upHit   = true;
        downHit = true;
    }

    else if( events.Clicked( events.mouse.Left ) )
    {
        up = true;

        upHit = true;
    }

    else if( events.Clicked( events.mouse.Right ) )
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


    //if( upHit )   CoutEndl("up")
    //if( downHit ) CoutEndl("up")
}
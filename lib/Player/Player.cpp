#include "Player.h"

void Player::Input()
{
    up   = false;
    down = true;

    upHit     = false;
    downHit   = false;

    if( events.Right1Pressed() && events.Right2Pressed() )
    {
        up   = false;
        down = false;

        upHit   = true;
        downHit = true;
    }

    else if( events.Right1Pressed() )
    {
        up = true;

        upHit = true;
    }

    else if( events.Right2Pressed() )
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
}
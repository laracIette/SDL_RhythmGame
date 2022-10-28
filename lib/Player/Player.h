#pragma once

#include "../../inc/Global.h"
#include "../Image/Image.h"

class Player : public Image
{
    bool up, down;
    bool upHit, downHit, middleHit;

public:
    Player() : Image(
        "assets/Skins/Player/Player0.png",
        {0, 0, 40, 60},
        {(float)WIDTH/6, (float)HEIGHT/2, 40, 60}
    )
    {
        up   = false;
        down = true;

        upHit     = false;
        downHit   = false;
    }

    void Input();
};

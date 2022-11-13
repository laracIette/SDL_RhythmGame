#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Hit
{

    class Coin : public HitObject
    {
    public:
        Coin()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Coins",
            {0, 0, 25, 25},
            {0, 0, 25, 25}
        )
        {}

        void CheckHitTiming()
        {
            if( difference < Time::Great )
            {
                isHit = true;
                /////////////////// ADD SCORE ///////////////////
            }
        }

        void Init()
        {
            (IsHitObjectHorizontal()) ? yOffset += getHitObjectOffsetHeight() : xOffset -= getHitObjectOffsetHeight();
            endTime = time;
        }
    };

}
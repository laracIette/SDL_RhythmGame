#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Coin : public HitObject
    {
    public:
    /**
        Coin inherits from HitObject
    */
        Coin() :
            HitObject(
                "assets/Skins/BaseSkin/HitObjects/Coins",
                {0, 0, 50, 50}
            )
        {}

        void CheckHitTiming()
        {
            if( difference < Time::Great )
            {
                isHit = true;
                hitSoundManager->Play( type );
                hitValue = 25;
                isReturnHitValue = true;
            }
        }

        void Init()
        {
            (IsHitObjectHorizontal()) ? yOffset += getHitObjectOffsetHeight() : xOffset -= getHitObjectOffsetHeight();
            endTime = time;
        }
    };

}
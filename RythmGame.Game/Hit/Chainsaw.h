#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Hit
{

    class Chainsaw : public HitObject
    {
        bool isHitLock;

    public:
        Chainsaw()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Chainsaws",
            {0, 0, 2048, 2048},
            {0, 0, 50, 50}
        )
        {}

        void Init()
        {
            isHitLock = false;

            (IsHitObjectHorizontal()) ? yOffset += getHitObjectOffsetHeight() : xOffset -= getHitObjectOffsetHeight();
            endTime = time;
        }

        void CheckHitTiming()
        {
            if( difference < Time::Great )
            {
                isHit = true;
                hitSoundManager->Play( type );
            }
        }

        bool IsHit()
        {
            if( !isHitLock && isHit )
            {
                isHitLock = true;
                return 1;
            }

            return 0;
        }
    };

}
#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Chainsaw : public HitObject
    {
        bool isHitLock;

    public:
    /**
        Chainsaw inherits from HitObject
    */
        Chainsaw()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Chainsaws",
            {0, 0, 135, 135}
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
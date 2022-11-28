#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Ghost : public HitObject
    {
    public:
    /**
        Ghost inherits from HitObject
    */
        Ghost() :
            HitObject(
                "assets/Skins/BaseSkin/HitObjects/Ghosts",
                {0, 0, 100, 100}
            )
        {}

        void Init()
        {
            (IsHitObjectHorizontal()) ? yOffset += getHitObjectOffsetHeight() : xOffset -= getHitObjectOffsetHeight();
            endTime = time;
        }
    };

}
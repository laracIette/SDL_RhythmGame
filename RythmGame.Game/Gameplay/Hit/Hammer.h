#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Hammer : public HitObject
    {
    public:
    /**
        Hammer inherits from HitObject
    */
        Hammer()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Hammers",
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
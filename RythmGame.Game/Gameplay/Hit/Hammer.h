#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Hammer : public HitObject
    {
    public:
        Hammer()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Hammers",
            {0, 0, 50, 50},
            {0, 0, 50, 50}
        )
        {}

        void Init()
        {
            (IsHitObjectHorizontal()) ? yOffset += getHitObjectOffsetHeight() : xOffset -= getHitObjectOffsetHeight();
            endTime = time;
        }
    };

}
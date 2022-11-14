#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Note : public HitObject
    {

    public:
        Note()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Notes",
            {0, 0, 2048, 2048},
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
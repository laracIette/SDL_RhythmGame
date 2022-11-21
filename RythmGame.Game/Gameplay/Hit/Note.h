#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Note : public HitObject
    {

    public:
    /*
        Note inherits from HitObject
    */
        Note()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Notes",
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
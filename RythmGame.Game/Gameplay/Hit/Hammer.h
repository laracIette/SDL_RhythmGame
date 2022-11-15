#ifndef RYTHMGAME_GAME_GAMEPLAY_HIT_HAMMER_H
#define RYTHMGAME_GAME_GAMEPLAY_HIT_HAMMER_H


#include "../../../includes.h"


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

#endif // RYTHMGAME_GAME_GAMEPLAY_HIT_HAMMER_H
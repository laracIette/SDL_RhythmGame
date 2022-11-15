#ifndef RYTHMGAME_GAME_GAMEPLAY_HIT_GHOST_H
#define RYTHMGAME_GAME_GAMEPLAY_HIT_GHOST_H


#include "../../../includes.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Ghost : public HitObject
    {
    public:
        Ghost()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Ghosts",
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

#endif // RYTHMGAME_GAME_GAMEPLAY_HIT_GHOST_H
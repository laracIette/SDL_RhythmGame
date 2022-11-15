#ifndef RYTHMGAME_GAME_GAMEPLAY_HIT_NOTE_H
#define RYTHMGAME_GAME_GAMEPLAY_HIT_NOTE_H


#include "../../../includes.h"


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

#endif // RYTHMGAME_GAME_GAMEPLAY_HIT_NOTE_H
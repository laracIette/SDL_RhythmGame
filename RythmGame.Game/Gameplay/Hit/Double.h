#ifndef RYTHMGAME_GAME_GAMEPLAY_HIT_DOUBLE_H
#define RYTHMGAME_GAME_GAMEPLAY_HIT_DOUBLE_H


#include "../../../includes.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Double : public HitObject
    {
        bool isUpPressed, isDownPressed;
        unsigned int upPressedTime, downPressedTime;

    public:
        Double()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Doubles",
            {0, 0, 50, 150},
            {0, 0, 50, 50}
        )
        {}

        void Init()
        {
            isUpPressed = false;
            isDownPressed = false;

            (IsHitObjectHorizontal()) ? SetH( 150 ) : SetW( 150 );
            endTime = time;
        }

        bool CheckHitting()
        {
        // register moment for each click
            if( !isUpPressed &&
                ( ( inputManager.Left2Pressed()  && ((direction == LEFT  && isHorizontal) || (direction == UP && !isHorizontal)) )
               || ( inputManager.Right1Pressed() && (direction  == RIGHT && isHorizontal) )
               || ( inputManager.Right2Pressed() && (direction  == DOWN  && !isHorizontal) )  )
            )
            {
                isUpPressed = true;
                upPressedTime = currentTime;
            }
            if( !isDownPressed &&
                ( ( inputManager.Left1Pressed()  && ((direction == LEFT  && isHorizontal) || (direction == UP && !isHorizontal)) )
               || ( inputManager.Right2Pressed() && (direction  == RIGHT && isHorizontal) )
               || ( inputManager.Right1Pressed() && (direction  == DOWN  && !isHorizontal) ) )
            )
            {
                isDownPressed = true;
                downPressedTime = currentTime;
            }
        // hitValue = highest difference from time
            if( isUpPressed && isDownPressed )
            {
                difference = highest(
                    abs( (int)upPressedTime   - (int)offsetTime - (int)time ),
                    abs( (int)downPressedTime - (int)offsetTime - (int)time )
                );
                return 1;
            }

            return 0;
        }
    };

}

#endif // RYTHMGAME_GAME_GAMEPLAY_HIT_DOUBLE_H
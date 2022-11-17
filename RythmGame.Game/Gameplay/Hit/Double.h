#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Double : public HitObject
    {
        bool isUpPressed, isDownPressed;
        std::chrono::high_resolution_clock::time_point upPressedTime, downPressedTime;

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
                    abs( std::chrono::duration_cast<std::chrono::milliseconds>(upPressedTime   - offsetTime).count() - time ),
                    abs( std::chrono::duration_cast<std::chrono::milliseconds>(downPressedTime - offsetTime).count() - time )
                );
                return 1;
            }

            return 0;
        }
    };

}
#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Double : public HitObject
    {
        bool isUpPressed, isDownPressed;
        std::chrono::high_resolution_clock::time_point upPressedTime, downPressedTime;

    public:
    /*
        Double inherits from HitObject
    */
        Double()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Doubles",
            {0, 0, 100, 100}
        )
        {}

        void Init()
        {
            isUpPressed = false;
            isDownPressed = false;

            (IsHitObjectHorizontal()) ? SetH( 300 ) : SetW( 300 );
            endTime = time;
        }

        bool CheckHitting()
        {
        /*
            register moment for each click
        */
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
        /*
            hitValue = highest difference from time
        */
            if( isUpPressed && isDownPressed )
            {
                difference = highest(
                    getDuration<Milliseconds>(upPressedTime,   offsetTime) - time,
                    getDuration<Milliseconds>(downPressedTime, offsetTime) - time
                );
                return 1;
            }

            return 0;
        }
    };

}
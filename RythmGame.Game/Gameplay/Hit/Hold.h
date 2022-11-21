#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Hold : public HitObject
    {
        bool isEndHitValueReturned;

        std::chrono::high_resolution_clock::time_point lastTickTime;

        bool isLastTickTime;


    public:
    /*
        Hold inherits from HitObject
    */
        Hold()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Holds",
            {0, 0, 100, 100}
        )
        {}

        void Init()
        {
            if( IsHitObjectHorizontal() )
            {
                SetW( (float)(endTime - time)*velocity + H() );
                xOffset = (direction == LEFT) ? -(W()/2 - H()/2) : (W()/2 - H()/2);
                yOffset += getHitObjectOffsetHeight();
            }
            else
            {
                SetH( (float)(endTime - time)*velocity + W() );
                yOffset = (direction == UP) ? -(H()/2 - W()/2) : (H()/2 - W()/2);
                xOffset -= getHitObjectOffsetHeight();
            }

            isEndHitValueReturned = false;
            isLastTickTime = false;
        }

        void DoThingsAfterHit()
        {
            if( !isLastTickTime )
            {
                isLastTickTime = true;
                lastTickTime = currentTime;
            }

            if( !isEndHitValueReturned && (hitValue >= 0) && !CheckHitting() )
            {
                isEndHitValueReturned = true;
                difference = abs( getDuration<Milliseconds>(currentTime, offsetTime) - endTime );

                CheckHitTiming();
            }

            if( !isEndHitValueReturned && (getDuration<Milliseconds>(currentTime, lastTickTime) > 300) )
            {
                lastTickTime = currentTime;
                hitSoundManager->Play( type );
            }

        }

        bool IsHit()
        {
            return (isHit && isEndHitValueReturned) ;
        }
    };

}
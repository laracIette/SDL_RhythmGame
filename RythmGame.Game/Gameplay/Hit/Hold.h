#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit
{

    class Hold : public HitObject            ///////////////////////// TO DO /////////////////////////
    {
        bool isEndHitValueReturned;

        unsigned int lastTickTime;

        bool isLastTickTime;


    public:

        Hold()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Holds",
            {0, 0, 50, 50},
            {0, 0, 50, 50}
        )
        {}

        void Init()
        {
            if( IsHitObjectHorizontal() )
            {
                SetW( ((float)endTime - (float)time)*velocity + H() );
                xOffset = (direction == LEFT) ? -(W()/2 - H()/2) : (W()/2 - H()/2);
                yOffset += getHitObjectOffsetHeight();
            }
            else
            {
                SetH( ((float)endTime - (float)time)*velocity + W() );
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
                difference = abs( (int)currentTime - (int)offsetTime - (int)endTime );

                CheckHitTiming();
            }

            if( !isEndHitValueReturned && (((int)currentTime - (int)lastTickTime) > 300) )
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
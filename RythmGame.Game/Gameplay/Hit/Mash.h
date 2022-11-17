#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Gameplay::Hit ////////////////// SCORE //////////////////
{

    class Mash : public HitObject
    {
        unsigned int hits;
        std::chrono::high_resolution_clock::time_point lastHitTime;

        bool isHitBlocked;
        bool isHitted;

    public:

        Mash()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Mashs",
            {0, 0, 150, 150},
            {0, 0, 150, 150}
        )
        {}

        void Init()
        {
            hits = 0;
            isHitBlocked = false;
            isHitted = false;
        }

        void DoThings()
        {
            if( std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - offsetTime).count() < time )
            {
                (IsHitObjectHorizontal()) ? xOffset = 0 : yOffset = 0;
            }
            else if( std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - offsetTime).count() >= endTime )
            {

                if( IsHitObjectHorizontal() )
                {
                    xOffset = (direction == LEFT) ? -((float)endTime - (float)time)*velocity
                                                  :  ((float)endTime - (float)time)*velocity;
                }
                else
                {
                    yOffset = (direction == UP) ? -((float)endTime - (float)time)*velocity
                                                :  ((float)endTime - (float)time)*velocity;
                }
            }
            else
            {
                if( IsHitObjectHorizontal() )
                {
                    xOffset = (direction == LEFT) ?  (float)(time + std::chrono::duration_cast<std::chrono::milliseconds>(offsetTime - currentTime).count())*velocity
                                                  : -(float)(time + std::chrono::duration_cast<std::chrono::milliseconds>(offsetTime - currentTime).count())*velocity;
                }
                else
                {
                    yOffset = (direction == UP) ?  (float)(time + std::chrono::duration_cast<std::chrono::milliseconds>(offsetTime - currentTime).count())*velocity
                                                : -(float)(time + std::chrono::duration_cast<std::chrono::milliseconds>(offsetTime - currentTime).count())*velocity;
                }
            }

        }

        bool CheckHitting()
        {
            if( ( inputManager.LeftPressed()  && ((direction == LEFT  && isHorizontal) || (direction == UP   && !isHorizontal)) )
             || ( inputManager.RightPressed() && ((direction == RIGHT && isHorizontal) || (direction == DOWN && !isHorizontal)) )
            )
            {
                return 1;
            }

            return 0;
        }

        void CheckHitTiming()
        {
            if( difference < Time::Meh )
            {
                isHit = true;

                hitValue = Accuracy::Perfect;

                lastHitTime = currentTime;
            }
        }

        void DoThingsAfterHit()
        {
            if( isHitBlocked )
                return;

            if( (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - offsetTime).count() - endTime) > Time::Meh )
            {
                isReturnHitValue = true;
                isHitBlocked = true;
                return;
            }

            if( std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastHitTime).count() > 333 )
            {
                isHitBlocked = true;
                hitValue = Accuracy::Miss;
                isReturnHitValue = true;
            }

            if( !CheckHitting() )
                return;


            isHitted = false;

            if( (direction == LEFT && isHorizontal) || (direction == UP && !isHorizontal) )
            {
                if( inputManager.Left1PressedNoLock() )
                {
                    hits++;
                    inputManager.LockLeft1();
                    isHitted = true;
                }
                if( inputManager.Left2PressedNoLock() )
                {
                    hits++;
                    inputManager.LockLeft2();
                    isHitted = true;
                }
            }
            else if( (direction == RIGHT && isHorizontal) || (direction == DOWN && !isHorizontal) )
            {
                if( inputManager.Right1PressedNoLock() )
                {
                    hits++;
                    inputManager.LockRight1();
                    isHitted = true;
                }
                if( inputManager.Right2PressedNoLock() )
                {
                    hits++;
                    inputManager.LockRight2();
                    isHitted = true;
                }
            }

            if( isHitted )
            {
                lastHitTime = currentTime;
                hitSoundManager->Play( type );
                hitValue = 10;
                isReturnHitValue = true;
            }

        }
    };

}
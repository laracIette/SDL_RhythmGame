#pragma once

#include <SDL.h>
#include <iostream>

#include "../Utils/Time.h"
#include "../Utils/GameSettings.h"
#include "../Events/InputManager.h"

#include "../../RythmGame.Graphics/Animation/Animation.h"
#include "../../RythmGame.Sound/HitSoundManager/HitSoundManager.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Graphics;
using namespace RythmGame::Sound;

namespace RythmGame::Game::Hit
{

    enum ObjectTypes {
        NOTE = 1,
        HOLD,
        DOUBLE,
        MASH,
        GHOST,
        COIN,
        HAMMER,
        CHAINSAW
    };

    enum Directions {
        LEFT = 1,
        RIGHT,
        UP,
        DOWN
    };

    namespace Time
    {
        static const int Perfect{ 50 };
        static const int Great{ 150 };
        static const int Meh{ 300 };
        static const int Miss{ 450 };
    }

    namespace Accuracy
    {
        static const int Perfect{ 0 };
        static const int Great{ 1 };
        static const int Meh{ 2 };
        static const int Miss{ 3 };
    }


    class HitObject : public Animation
    {

    protected:
        bool isHit;
        bool isShown;
        bool isReturnHitValue;

        char hitValue;

        float xOffset;
        float yOffset;

    public:
        unsigned char type, direction;

        unsigned int time, endTime;

        unsigned int difference;

        bool isUp;

        void DrawHit( float x, float y )
        {Time::Great;
            SDL_SetRenderDrawColor( window->renderer, 255, 255, 255, 255 );

            for( float x2{ x - 50 }; x2 < (x + 50); ++x2 )
            {
                SDL_RenderDrawPoint( window->renderer, x2, y );
            }
            for( float y2{ y - 50 }; y2 < (y + 50); ++y2 )
            {
                SDL_RenderDrawPoint( window->renderer, x, y2 );
            }
        }

        bool IsHitObjectHorizontal()
        {
            return ((direction == LEFT) || (direction == RIGHT));
        }

    // HitObject inherits from Image
        HitObject( std::string path, SDL_Rect src, Rect dest ) : Animation( path, src, dest )
        {
            isHit            = false;
            isShown          = false;
            isReturnHitValue = false;

            xOffset = 0;
            yOffset = 0;
        }

    // returns the hitValue if isReturnHitValue is true
    // else returns -1
        char GetHitValue()
        {
            if( isReturnHitValue )
            {
                isReturnHitValue = false;
                std::cout << 'v' << (int)hitValue << std::endl;
                return hitValue;
            }
            return -1;
        }

        virtual bool IsHit() { return isHit; }

        float getHitObjectOffsetHeight()
        {
            return (isUp) ? -(float)HEIGHT/10 : (float)HEIGHT/10;
        }


    // initialises the HitObject
        virtual void Init() {}

    // sets the pos of the HitObject
        void SetPos()
        {
            switch( direction )
            {
            case LEFT:
                SetX( (float)WIDTH/2 - ((float)time + (float)offsetTime - (float)currentTime)*velocity + xOffset );
                SetY( (float)HEIGHT/2 + yOffset );
                break;

            case RIGHT:
                SetX( (float)WIDTH/2 + ((float)time + (float)offsetTime - (float)currentTime)*velocity + xOffset );
                SetY( (float)HEIGHT/2 + yOffset );
                break;

            case UP:
                SetX( (float)WIDTH/2 + xOffset );
                SetY( (float)HEIGHT/2 - ((float)time + (float)offsetTime - (float)currentTime)*velocity + yOffset );
                break;

            case DOWN:
                SetX( (float)WIDTH/2 + xOffset );
                SetY( (float)HEIGHT/2 + ((float)time + (float)offsetTime - (float)currentTime)*velocity + yOffset );
                break;

            default:
                break;
            }
        }

    // affects a value to hitValue
        virtual void CheckHitTiming()
        {
            isHit = true;
            isReturnHitValue = true;

            if( difference >= Time::Meh )
            {
                hitValue = Accuracy::Miss;
                return;
            }

            if( difference < Time::Perfect )
            {
                hitValue = Accuracy::Perfect;
            }
            else if( difference < Time::Great )
            {
                hitValue = Accuracy::Great;
            }
            else
            {
                hitValue = Accuracy::Meh;
            }
            hitSoundManager->Play( type );
        }

    // returns true if hitting the right note side
        virtual bool CheckHitting()
        {
            if( ( ((events.OnlyLeft2Pressed()  && isUp) || (events.OnlyLeft1Pressed()  && !isUp)) && ((direction == LEFT && isHorizontal) || (direction == UP   && !isHorizontal)) )
            || ( ((events.OnlyRight1Pressed() && isUp) || (events.OnlyRight2Pressed() && !isUp)) && (direction == RIGHT && isHorizontal) )
            || ( ((events.OnlyRight2Pressed() && isUp) || (events.OnlyRight1Pressed() && !isUp)) && (direction == DOWN  && !isHorizontal) )
            )
            {
                return 1;
            }

            return 0;
        }


    // does specific things by type if isHit
        virtual void DoThingsAfterHit()
        {
            if( W() > 2 )
            {
                SetW( W() - 0.1 );
                SetH( H() - 0.1 );
            }

        }

        virtual void DoThings() {}


        void Update()
        {
            difference = abs( (int)currentTime - (int)offsetTime - (int)time );

            DoThings();

            SetPos();

            if( !isShown && ((X() <= WIDTH + W()/2) || (X() >= -W()/2) || (Y() <= HEIGHT + H()/2) || (Y() >= -H()/2)) )
            {
                isShown = true;
            }

            if( !isHit && (difference < Time::Miss) && CheckHitting() )
            {
                CheckHitTiming();
            }

            if( isHit )
            {
                DoThingsAfterHit();
            }
        }

    // draws the HitObject if isShown is true
        virtual void DrawHitObject()
        {
            if( isShown ) Draw();

            DrawHit( X()-xOffset, Y()-yOffset );
        }

    // returns true if the HitObject needs to be erased
        bool Erase()
        {
            if( ((int)currentTime - (int)offsetTime - (int)endTime) > (int)Time::Miss )
            {
                return 1;
            }

            return 0;
        }
    };



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



    class Hold : public HitObject
    {
        bool isEndHitValueReturned;

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

        }

        void DoThingsAfterHit()
        {
            if( !isEndHitValueReturned && (hitValue >= 0) && !CheckHitting() )
            {
                isEndHitValueReturned = true;
                difference = abs( (int)currentTime - (int)offsetTime - (int)endTime );

                CheckHitTiming();
            }
        }

        bool IsHit()
        {
            return (isHit && isEndHitValueReturned) ;
        }
    };



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
                ( ( events.Left2Pressed()  && ((direction == LEFT  && isHorizontal) || (direction == UP && !isHorizontal)) )
            || ( events.Right1Pressed() && (direction  == RIGHT && isHorizontal) )
            || ( events.Right2Pressed() && (direction  == DOWN  && !isHorizontal) )  )
            )
            {
                isUpPressed = true;
                upPressedTime = currentTime;
            }
            if( !isDownPressed &&
                ( ( events.Left1Pressed()  && ((direction == LEFT  && isHorizontal) || (direction == UP && !isHorizontal)) )
            || ( events.Right2Pressed() && (direction  == RIGHT && isHorizontal) )
            || ( events.Right1Pressed() && (direction  == DOWN  && !isHorizontal) ) )
            )
            {
                isDownPressed = true;
                downPressedTime = currentTime;
            }
        // hitValue = highest difference from time
            if( isUpPressed && isDownPressed )
            {
                difference = highest(
                    abs( (int)upPressedTime - (int)offsetTime - (int)time ),
                    abs( (int)downPressedTime - (int)offsetTime - (int)time )
                );
                return 1;
            }

            return 0;
        }
    };



    class Mash : public HitObject
    {
        unsigned int hits;
        unsigned int lastHitTime;

        bool isHitBlocked;


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
        }

        void DoThings()
        {
            if( (currentTime - offsetTime) < time )
            {
                (IsHitObjectHorizontal()) ? xOffset = 0 : yOffset = 0;
            }
            else if( (currentTime - offsetTime) >= endTime )
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
                    xOffset = (direction == LEFT) ?  ((float)time + (float)offsetTime - (float)currentTime)*velocity
                                                : -((float)time + (float)offsetTime - (float)currentTime)*velocity;
                }
                else
                {
                    yOffset = (direction == UP) ?  ((float)time + (float)offsetTime - (float)currentTime)*velocity
                                                : -((float)time + (float)offsetTime - (float)currentTime)*velocity;
                }
            }

        }

        bool CheckHitting()
        {
            if( ( events.LeftPressed()  && ((direction == LEFT  && isHorizontal) || (direction == UP   && !isHorizontal)) )
            || ( events.RightPressed() && ((direction == RIGHT && isHorizontal) || (direction == DOWN && !isHorizontal)) )
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

            if( ((int)currentTime - (int)offsetTime - (int)endTime) > Time::Meh )
            {
                isReturnHitValue = true;
                isHitBlocked = true;
                return;
            }

            if( (currentTime - lastHitTime) > 333 )
            {
                isHitBlocked = true;
                hitValue = Accuracy::Miss;
                isReturnHitValue = true;
            }

            if( !CheckHitting() )
                return;


            if( (direction == LEFT && isHorizontal) || (direction == UP && !isHorizontal) )
            {
                if( events.Left1PressedNoLock() )
                {
                    hits++;
                    events.LockLeft1();
                    lastHitTime = currentTime;
                    hitSoundManager->Play( type );
                }
                if( events.Left2PressedNoLock() )
                {
                    hits++;
                    events.LockLeft2();
                    lastHitTime = currentTime;
                    hitSoundManager->Play( type );
                }
            }
            else if( (direction == RIGHT && isHorizontal) || (direction == DOWN && !isHorizontal) )
            {
                if( events.Right1PressedNoLock() )
                {
                    hits++;
                    events.LockRight1();
                    lastHitTime = currentTime;
                    hitSoundManager->Play( type );
                }
                if( events.Right2PressedNoLock() )
                {
                    hits++;
                    events.LockRight2();
                    lastHitTime = currentTime;
                    hitSoundManager->Play( type );
                }
            }

        }
    };



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



    class Coin : public HitObject
    {
    public:
        Coin()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Coins",
            {0, 0, 25, 25},
            {0, 0, 25, 25}
        )
        {}

        void CheckHitTiming()
        {
            if( difference < Time::Great )
            {
                isHit = true;
                /////////////////// ADD SCORE ///////////////////
            }
        }

        void Init()
        {
            (IsHitObjectHorizontal()) ? yOffset += getHitObjectOffsetHeight() : xOffset -= getHitObjectOffsetHeight();
            endTime = time;
        }
    };



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



    class Chainsaw : public HitObject
    {
        bool isHitLock;

    public:
        Chainsaw()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Chainsaws",
            {0, 0, 2048, 2048},
            {0, 0, 50, 50}
        )
        {}

        void Init()
        {
            isHitLock = false;

            (IsHitObjectHorizontal()) ? yOffset += getHitObjectOffsetHeight() : xOffset -= getHitObjectOffsetHeight();
            endTime = time;
        }

        void CheckHitTiming()
        {
            if( difference < Time::Great )
            {
                isHit = true;
                hitSoundManager->Play( type );
            }
        }

        bool IsHit()
        {
            if( !isHitLock && isHit )
            {
                isHitLock = true;
                return 1;
            }

            return 0;
        }
    };

}
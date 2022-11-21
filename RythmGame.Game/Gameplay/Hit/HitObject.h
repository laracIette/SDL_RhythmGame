#pragma once

#include <SDL.h>
#include <iostream>
#include <chrono>

#include "../../Utils/Time.h"
#include "../../Utils/Point.h"
#include "../../Utils/GameSettings.h"
#include "../../Events/InputManager.h"

#include "../../../RythmGame.Graphics/Animation/Animation.h"
#include "../../../RythmGame.Sound/HitSoundManager/HitSoundManager.h"

#include "../../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Graphics;
using namespace RythmGame::Sound;
using namespace RythmGame::Framework;


namespace RythmGame::Game::Gameplay::Hit
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
        char type, direction;

        int time, endTime;

        int difference;

        bool isUp;

    // HitObject inherits from Animation
        HitObject( std::string path, SDL_Rect src, Rect dest ) : Animation( path, src, dest )
        {
            isHit            = false;
            isShown          = false;
            isReturnHitValue = false;

            xOffset = 0;
            yOffset = 0;
        }

        void DrawHit( float x, float y )
        {
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
            return (isUp) ? -1080/10 : 1080/10;
        }


    // initialises the HitObject
        virtual void Init() {}

    // sets the pos of the HitObject
        void SetPos()
        {
            switch( direction )
            {
            case LEFT:
                SetX( 1920/2 - (float)(time + getDuration<Milliseconds>(offsetTime, currentTime))*velocity + xOffset );
                SetY( 1080/2 + yOffset );
                break;

            case RIGHT:
                SetX( 1920/2 + (float)(time + getDuration<Milliseconds>(offsetTime, currentTime))*velocity + xOffset );
                SetY( 1080/2 + yOffset );
                break;

            case UP:
                SetX( 1920/2 + xOffset );
                SetY( 1080/2 - (float)(time + getDuration<Milliseconds>(offsetTime, currentTime))*velocity + yOffset );
                break;

            case DOWN:
                SetX( 1920/2 + xOffset );
                SetY( 1080/2 + (float)(time + getDuration<Milliseconds>(offsetTime, currentTime))*velocity + yOffset );
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
            if( ( ((inputManager.OnlyLeft2Pressed()  && isUp) || (inputManager.OnlyLeft1Pressed()  && !isUp)) && ((direction == LEFT && isHorizontal) || (direction == UP   && !isHorizontal)) )
             || ( ((inputManager.OnlyRight1Pressed() && isUp) || (inputManager.OnlyRight2Pressed() && !isUp)) && (direction == RIGHT && isHorizontal) )
             || ( ((inputManager.OnlyRight2Pressed() && isUp) || (inputManager.OnlyRight1Pressed() && !isUp)) && (direction == DOWN  && !isHorizontal) )
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
            difference = abs( getDuration<Milliseconds>(currentTime, offsetTime) - time );

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
            if( (getDuration<Milliseconds>(currentTime, offsetTime) - endTime) > (int)Time::Miss )
            {
                return 1;
            }

            return 0;
        }
    };

}
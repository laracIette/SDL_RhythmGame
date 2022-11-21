#pragma once

#include "../../../../RythmGame.Graphics/Image/Image.h"
#include "../../../../RythmGame.Graphics/TextureManager/TextureManager.h"
#include "../../../Events/InputManager.h"
#include "../../../Utils/Time.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Game::Menu::StartScreen::Button
{
    enum Positions {
        TopLeft = 0,
        TopRight,
        BottomLeft,
        BottomRight
    };

    enum Base {
        Exit = 0,
        Download,
        Settings
    };

    enum Play {
        PlayBack = 0,
        PlaySolo,
        PlayMulti,
        PlayOffline
    };

    class ButtonTemplate : public Image
    {
        int position;
        float zoom;

        float posX, posY;

        std::string path;

    public:
        ButtonTemplate( std::string path, int position )
         : Image(
            path,
            {0, 0, 240, 240},
            {1920/2, 1080/2, 240, 240}
        )
        {
            this->path = path;
            this->position = position;
            zoom = 1.0f;

            posX = dest.x;
            posY = dest.y;

            isHoover = false;
        }

        ~ButtonTemplate()
        {}

        void Hoover()
        {
            isHoover = false;

            switch( position )
            {
            case TopLeft:
                if( (inputManager.mouse.pos.x > Resize( dest.x )) && (inputManager.mouse.pos.x < Resize( dest.x + dest.w*zoom ))
                 && (inputManager.mouse.pos.y > Resize( dest.y )) && (inputManager.mouse.pos.y < Resize( dest.y + dest.h*zoom )) )
                {
                    isHoover = true;
                }
                break;

            case TopRight:
                if( (inputManager.mouse.pos.x > Resize( dest.x - dest.w*zoom )) && (inputManager.mouse.pos.x < Resize( dest.x ))
                 && (inputManager.mouse.pos.y > Resize( dest.y )) && (inputManager.mouse.pos.y < Resize( dest.y + dest.h*zoom )) )
                {
                    isHoover = true;
                }
                break;

            case BottomLeft:
                if( (inputManager.mouse.pos.x > Resize( dest.x )) && (inputManager.mouse.pos.x < Resize( dest.x + dest.w*zoom ))
                 && (inputManager.mouse.pos.y > Resize( dest.y - dest.h*zoom )) && (inputManager.mouse.pos.y < Resize( dest.y )) )
                {
                    isHoover = true;
                }
                break;

            case BottomRight:
                if( (inputManager.mouse.pos.x > Resize( dest.x - dest.w*zoom )) && (inputManager.mouse.pos.x < Resize( dest.x ))
                 && (inputManager.mouse.pos.y > Resize( dest.y - dest.h*zoom )) && (inputManager.mouse.pos.y < Resize( dest.y )) )
                {
                    isHoover = true;
                }
                break;

            default:
                break;
            }

            if( isHoover && (zoom < 1.1) )
            {
                zoom += (float)deltaTime/500;
            }
            else if( !isHoover && (zoom > 1) )
            {
                zoom -= (float)deltaTime/500;
            }
        }

        void DrawButton()
        {
            switch( position )
            {
            case TopLeft:
                posX = dest.x + dest.w*zoom/2;
                posY = dest.y + dest.h*zoom/2;
                break;

            case TopRight:
                posX = dest.x + dest.w*zoom/2 - dest.w*zoom;
                posY = dest.y + dest.h*zoom/2;
                break;

            case BottomLeft:
                posX = dest.x + dest.w*zoom/2;
                posY = dest.y + dest.h*zoom/2 - dest.h*zoom;
                break;

            case BottomRight:
                posX = dest.x + dest.w*zoom/2 - dest.w*zoom;
                posY = dest.y + dest.h*zoom/2 - dest.h*zoom;
                break;

            default:
                break;
            }


            Draw( {posX, posY, dest.w*zoom, dest.h*zoom} );
        }
    };

}
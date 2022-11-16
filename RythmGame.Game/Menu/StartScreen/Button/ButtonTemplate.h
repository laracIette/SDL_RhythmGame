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
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    class ButtonTemplate : public Image
    {
        int position;
        float zoom;

    public:
        ButtonTemplate( std::string path, int position )
         : Image(
            path,
            {0, 0, 240, 240},
            {(float)WIDTH/2, (float)HEIGHT/2, 240, 240}
        )
        {
            this->position = position;
            zoom = 1.0f;
        }

        ~ButtonTemplate()
        {}

        bool Clicked()
        {
            return (Hoover() && inputManager.Clicked( inputManager.mouse.Left ));
        }

        bool Hoover()
        {
            bool isZoom{ false };

            switch( position )
            {
            case TopLeft:
                if( (inputManager.mouse.pos.x > dest.x) && (inputManager.mouse.pos.x < (dest.x + dest.w))
                 && (inputManager.mouse.pos.y > dest.y) && (inputManager.mouse.pos.y < (dest.y + dest.h)) )
                {
                    isZoom = true;
                }
                break;

            case TopRight:
                if( (inputManager.mouse.pos.x > (dest.x - dest.w)) && (inputManager.mouse.pos.x < dest.x)
                 && (inputManager.mouse.pos.y > dest.y) && (inputManager.mouse.pos.y < (dest.y + dest.h)) )
                {
                    isZoom = true;
                }
                break;

            case BottomLeft:
                if( (inputManager.mouse.pos.x > dest.x) && (inputManager.mouse.pos.x < (dest.x + dest.w))
                 && (inputManager.mouse.pos.y > (dest.y-dest.h)) && (inputManager.mouse.pos.y < dest.y) )
                {
                    isZoom = true;
                }
                break;

            case BottomRight:
                if( (inputManager.mouse.pos.x > (dest.x - dest.w)) && (inputManager.mouse.pos.x < dest.x)
                 && (inputManager.mouse.pos.y > (dest.y-dest.h)) && (inputManager.mouse.pos.y < dest.y) )
                {
                    isZoom = true;
                }
                break;

            default:
                break;
            }

            if( isZoom && (zoom < 1.1) )
            {
                zoom += (float)deltaTime/500;
            }
            else if( !isZoom && (zoom > 1) )
            {
                zoom -= (float)deltaTime/500;
            }

            return isZoom;
        }

        void Draw()
        {
            int posX;
            int posY;

            switch( position )
            {
            case TopLeft:
                posX = (int)(dest.x);
                posY = (int)(dest.y);
                break;

            case TopRight:
                posX = (int)(dest.x-dest.w*zoom);
                posY = (int)(dest.y);
                break;

            case BottomLeft:
                posX = (int)(dest.x);
                posY = (int)(dest.y-dest.h*zoom);
                break;

            case BottomRight:
                posX = (int)(dest.x-dest.w*zoom);
                posY = (int)(dest.y-dest.h*zoom);
                break;

            default:
                break;
            }

            TextureManager::DrawTexture(
                tex,
                src,
                {posX, posY, (int)(dest.w*zoom), (int)(dest.h*zoom)}
            );
        }
    };

}
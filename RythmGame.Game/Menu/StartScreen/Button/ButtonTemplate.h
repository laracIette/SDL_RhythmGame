#pragma once

#include "../../../../RythmGame.Graphics/Image/Image.h"
#include "../../../../RythmGame.Graphics/TextureManager/TextureManager.h"
#include "../../../Events/InputManager.h"

#include "../../../Utils/Time.h"
#include "../../../Utils/GameSettings.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Game::Menu::StartScreen::Button
{

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
        std::string path;

    public:
    /**
        ButtonTemplate inherits from Image
    */
        ButtonTemplate( std::string _path, int _position ) :
            Image(
                _path,
                {1920/2, 1080/2, 240, 240},
                RenderStartScreen,
                8,
                _position
            )
        {
            path = _path;
        }

        virtual void Update()
        {
            Hoover();
            UpdateZoom();
        }

        void UpdateZoom()
        {
            if( isHoover && (zoom < 1.1) )
            {
                zoom += deltaTime/500;
            }
            else if( !isHoover && (zoom > 1) )
            {
                zoom -= deltaTime/500;
            }
        }
    };

}
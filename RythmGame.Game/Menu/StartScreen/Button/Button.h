#pragma once

#include "../../../../RythmGame.Graphics/Image/Positions/ImageTopLeft.h"
#include "../../../../RythmGame.Graphics/Image/Positions/ImageTopRight.h"
#include "../../../../RythmGame.Graphics/Image/Positions/ImageBottomLeft.h"
#include "../../../../RythmGame.Graphics/Image/Positions/ImageBottomRight.h"

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

    template<typename T>
    class Button : public T
    {

    public:
    /**
     *  Button inherits from Image
     */
        Button( std::string _path ) :
            T(
                _path,
                {1920/2, 1080/2, 240, 240},
                RenderStartScreen,
                8
            )
        {
        }

        virtual void Update()
        {
            T::Hoover();
            UpdateZoom();
        }

        void UpdateZoom()
        {
            if( T::isHoover && (T::zoom < 1.1) )
            {
                T::zoom += deltaTime/500;
            }
            else if( !T::isHoover && (T::zoom > 1) )
            {
                T::zoom -= deltaTime/500;
            }
        }
    };

}
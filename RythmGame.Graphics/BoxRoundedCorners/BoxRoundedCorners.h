#pragma once

#include <iostream>

#include "../../inc/SDL-release-2.24.0/include/SDL.h"

#include "../../RythmGame.Game/Utils/GameSettings.h"
#include "../../RythmGame.Game/Events/InputManager.h"

#include "../TextureManager/TextureManager.h"

#include "../Renderable.h"

#include "../RenderQueue/RenderQueue.h"

#include "../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;

namespace RythmGame::Graphics
{

    class BoxRoundedCorners : public Renderable
    {
        SDL_Texture *corner;
        Rect         dest;
        float        size;
        RGB          color;

    public:
        BoxRoundedCorners( Rect _dest, std::vector<std::pair<int, int>> _pairs, RGB _color = White, const char *_path = "assets/UI/RoundedCorner.png" )
        {
            corner = TextureManager::LoadTexture( _path );

            dest = _dest;

            color = _color;

            size = lowest( dest.w, dest.h )/5;

            if( size > 25 )
            {
                size = 25;
            }

            for( std::pair<int, int> pair : _pairs )
            {
                renderQueue->AddQueue( this, pair.first, pair.second );
            }
        }
        ~BoxRoundedCorners();

        void SetY( float _y );

        void Draw();

        bool IsNotHooverLeftClicked();
    };

}
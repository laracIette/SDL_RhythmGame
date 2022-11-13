#pragma once

#include "../Utils/Point.h"
#include "../Utils/Time.h"
#include "../Utils/Metrics.h"
#include "../Utils/GameSettings.h"

#include "../Events/InputManager.h"

#include "../Player/Player.h"
#include "../Map/Map.h"

#include "../../RythmGame.Graphics/Image/Image.h"
#include "../../RythmGame.Framework/Window/Window.h"
#include "../../RythmGame.Sound/HitSoundManager/HitSoundManager.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Graphics;
using namespace RythmGame::Framework;
using namespace RythmGame::Sound;
using namespace RythmGame::Game::Events;


namespace RythmGame::Game
{

    class Run
    {
        bool isRunning;

        unsigned int lastFrameTime;

        Player *player;
        Map *map;

        bool isStarted;

        Image *horizontalForeground;
        Image *verticalForeground;

    public:
        Run();
        ~Run();

        void Init();

        void Update();

        void Render();
        void Clear();

        bool Running() { return isRunning; }

    };

}
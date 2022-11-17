#pragma once

#include <chrono>

#include "../Utils/Point.h"
#include "../Utils/Time.h"
#include "../Utils/Metrics.h"
#include "../Utils/GameSettings.h"

#include "../Events/InputManager.h"

#include "../Gameplay/Player/Player.h"
#include "../Gameplay/Map/Map.h"

#include "../Menu/StartScreen/Screen/Screen.h"

#include "../../RythmGame.Framework/Window/Window.h"
#include "../../RythmGame.Sound/HitSoundManager/HitSoundManager.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Game::Gameplay;
using namespace RythmGame::Framework;
using namespace RythmGame::Sound;
using namespace RythmGame::Game::Menu::StartScreen;


namespace RythmGame::Game
{

    class Run
    {
        bool isRunning;

        std::chrono::high_resolution_clock::time_point lastFrameTime;

        Player *player;
        Map *map;

        bool isStarted;

        Screen *startScreen;

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
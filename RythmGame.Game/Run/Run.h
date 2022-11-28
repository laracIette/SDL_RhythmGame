#pragma once

#include <chrono>
#include <SDL_ttf.h>

#include "../Utils/Point.h"
#include "../Utils/Time.h"
#include "../Utils/Metrics.h"
#include "../Utils/GameSettings.h"

#include "../Events/InputManager.h"

#include "../Gameplay/Player/Player.h"
#include "../Gameplay/Map/Map.h"

#include "../Menu/StartScreen/Screen/Screen.h"
#include "../Menu/MapSelection/Screen/Screen.h"

#include "../../RythmGame.Sound/HitSoundManager/HitSoundManager.h"
#include "../../RythmGame.Graphics/ImageManager.h"

#include "../Settings/Window.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Game::Gameplay;
using namespace RythmGame::Game::Menu;
using namespace RythmGame::Framework;
using namespace RythmGame::Sound;


namespace RythmGame::Game
{

    enum GameStates {
        STARTSCREEN = 0,
        MAPSELECTION,
        GAMEPLAY
    };

    class Run
    {
        bool isRunning;

        Player *player;
        Map *map;

        StartScreen::Screen  *startScreen;
        MapSelection::Screen *mapSelectionScreen;

        bool isSettings;

        int gameState;

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
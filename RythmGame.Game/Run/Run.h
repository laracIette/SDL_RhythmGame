#ifndef RYTHMGAME_GAME_RUN_H
#define RYTHMGAME_GAME_RUN_H

#include "../../includes.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Game::Gameplay;
using namespace RythmGame::Framework;
using namespace RythmGame::Sound;


namespace RythmGame::Game
{

    class Run
    {
        bool isRunning;

        unsigned int lastFrameTime;

        Player *player;
        Map *map;

        bool isStarted;

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

#endif // RYTHMGAME_GAME_RUN_H
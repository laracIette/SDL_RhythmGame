#ifndef RYTHMGAME_GAME_GAMEPLAY_MAP_H
#define RYTHMGAME_GAME_GAMEPLAY_MAP_H

#include "../../../includes.h"

using namespace RythmGame::Game::Gameplay::Hit;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Sound;
using namespace RythmGame::Graphics;

namespace RythmGame::Game::Gameplay
{

    class Map
    {
        std::vector<HitObject *> hitObjects;

        Music *music;

        unsigned int pausedTime;

        bool isPaused;

        unsigned int accuracyHits[4];
        Accuracy *accuracy;

        char tempAcc;

        Combo *combo;
        unsigned int highestCombo;

        Score *score;

        Image *horizontalForeground;
        Image *verticalForeground;

    public:
        Map( std::string path );
        ~Map();

        void Update();
        void Draw();

        void Start();
        void Pause();

        void Close();

        void SetAccuracy();
    };

}

#endif // RYTHMGAME_GAME_GAMEPLAY_MAP_H
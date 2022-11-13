#pragma once

#include <fstream>
#include <string>

#include "../Hit/HitObject.h"
#include "../Utils/Time.h"

#include "../../RythmGame.Sound/Music/Music.h"

using namespace RythmGame::Game::Hit;
using namespace RythmGame::Sound;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Game
{

    class Map
    {
        std::vector<HitObject *> hitObjects;

        Music *music;

        unsigned int pausedTime;

        bool isPaused;

        unsigned int accuracyHits[4];
        unsigned int oldAcc;

        char tempAcc;

        unsigned int combo, highestCombo;

        unsigned int score;

    public:
        Map( std::string path );
        ~Map();

        void Update();
        void Draw();

        void Start();
        void Pause();

        void Close();

        float GetAccuracy();
    };

}
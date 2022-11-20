#pragma once

#include <fstream>
#include <string>
#include <chrono>

#include "../Score/Score.h"
#include "../Combo/Combo.h"
#include "../Accuracy/Accuracy.h"
#include "../../Utils/Time.h"
#include "../Dim.h"
#include "../../Song/Song.h"



using namespace RythmGame::Game::Utils;
using namespace RythmGame::Graphics;

namespace RythmGame::Game::Gameplay
{

    class Map
    {
        Song *song;

        std::chrono::high_resolution_clock::time_point pausedTime;

        bool isPaused;

        Accuracy *accuracy;

        char tempAcc;

        Combo *combo;
        int highestCombo;

        Score *score;

        Dim *dim;

    public:
        Map( Song *newSong );
        ~Map();

        void Update();
        void Draw();

        void Start();
        void Pause();

        void Close();
    };

}
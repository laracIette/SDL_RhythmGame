#pragma once

#include <fstream>
#include <string>

#include "../Hit/HitObject.h"
#include "../Hit/Note.h"
#include "../Hit/Hold.h"
#include "../Hit/Double.h"
#include "../Hit/Mash.h"
#include "../Hit/Ghost.h"
#include "../Hit/Coin.h"
#include "../Hit/Hammer.h"
#include "../Hit/Chainsaw.h"
#include "../Score/Score.h"
#include "../Combo/Combo.h"
#include "../../Utils/Time.h"

#include "../../../RythmGame.Sound/Music/Music.h"
#include "../../../RythmGame.Graphics/Image/Image.h"

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
        unsigned int oldAcc;

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

        float GetAccuracy();
    };

}
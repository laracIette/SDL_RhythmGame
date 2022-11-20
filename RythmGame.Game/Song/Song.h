#pragma once

#include <string>

#include "../../RythmGame.Framework/File/File.h"

#include "../Gameplay/Hit/HitObject.h"
#include "../Gameplay/Hit/Note.h"
#include "../Gameplay/Hit/Hold.h"
#include "../Gameplay/Hit/Double.h"
#include "../Gameplay/Hit/Mash.h"
#include "../Gameplay/Hit/Ghost.h"
#include "../Gameplay/Hit/Coin.h"
#include "../Gameplay/Hit/Hammer.h"
#include "../Gameplay/Hit/Chainsaw.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Gameplay::Hit;

namespace RythmGame::Game
{

    class Song
    {
        File *songFile;

        std::string name;
        std::string author;
        std::string difficulty;

        float level;

        std::vector<HitObject *> hitObjects;

    public:
        Song( std::string path );
        ~Song();

        std::vector<HitObject *> &GetHitObjects();
    };


}
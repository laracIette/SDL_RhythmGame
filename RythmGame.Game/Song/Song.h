#pragma once

#include <string>
#include <vector>

#include "../../RythmGame.Framework/File/File.h"

#include "../../RythmGame.Graphics/Background.h"

#include "../../RythmGame.Sound/Music/Music.h"

#include "../Gameplay/Hit/HitObject.h"
#include "../Gameplay/Hit/Note.h"
#include "../Gameplay/Hit/Hold.h"
#include "../Gameplay/Hit/Double.h"
#include "../Gameplay/Hit/Mash.h"
#include "../Gameplay/Hit/Ghost.h"
#include "../Gameplay/Hit/Coin.h"
#include "../Gameplay/Hit/Hammer.h"
#include "../Gameplay/Hit/Chainsaw.h"

#include "../Utils/Metrics.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Gameplay::Hit;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Sound;

namespace RythmGame::Game
{

    class Song
    {
        File *songFile;

        std::string name;
        std::string author;
        std::string difficulty;

        float level;

        Background *background;

        std::vector<HitObject *> hitObjects;

        Music *music;

    public:
        Song( std::string path );
        ~Song();

        void FillHitObjects();

        float GetLevel();
        Image *GetBackground();

        std::vector<HitObject *> &GetHitObjects();

        Music *GetMusic();
    };


}
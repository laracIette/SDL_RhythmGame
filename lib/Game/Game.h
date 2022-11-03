#pragma once

#include "../Player/Player.h"
#include "../Map/Map.h"

class Game
{
    bool isRunning;

    unsigned int lastFrameTime;

    Player *player;
    Map *map;

    bool isStarted;

public:
    Game();
    ~Game();

    void Init();

    void Update();

    void Render();
    void Clear();

    bool Running() { return isRunning; }

};
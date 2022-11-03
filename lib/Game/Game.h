#pragma once

#include "../Player/Player.h"
#include "../Map/Map.h"

class Game
{
    bool isRunning;

    unsigned int lastFrameTime;

    SDL_Event event;

    Player *player;
    Map *map;

    bool isStarted;

public:
    Game();
    ~Game();

    void Init();

    void HandleEvents();
    void Update();

    void Render();
    void Clear();

    bool Running() { return isRunning; }

};
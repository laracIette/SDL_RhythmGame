#pragma once

#include "../Player/Player.h"
#include "../Map/Map.h"

class Game
{
    bool isRunning;

    unsigned int startTime;
    unsigned int lastFrameTime;

    SDL_Event event;

    Player *player;
    Map *map;

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
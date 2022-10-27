#pragma once

#include "../Player/Player.h"
#include "../Target/Target.h"

class Game
{
    bool isRunning;

    unsigned int startTime;
    unsigned int lastFrameTime;

    SDL_Event event;

    Player *player;

    std::vector<Target *> targets;
    bool newTargetLock;

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
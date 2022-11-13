#pragma once

#include "../../inc/Point.h"
#include "../../inc/Time.h"
#include "../../inc/Metrics.h"
#include "../../inc/GameSettings.h"
#include "../../inc/Events/Events.h"

#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Image/Image.h"
#include "../Window/Window.h"
#include "../Sound/HitSoundManager/HitSoundManager.h"

class Game
{
    bool isRunning;

    unsigned int lastFrameTime;

    Player *player;
    Map *map;

    bool isStarted;

    Image *horizontalForeground;
    Image *verticalForeground;

public:
    Game();
    ~Game();

    void Init();

    void Update();

    void Render();
    void Clear();

    bool Running() { return isRunning; }

};
#pragma once

#include "../../inc/Global.h"
#include "../../inc/HitObject.h"
#include "../SoundManager/SoundManager.h"

class Map
{
    std::vector<HitObject *> hitObjects;

    SoundManager *music;

    unsigned int offsetTime, pausedTime;

    bool isPaused;

    std::vector<char> accuracyHits;

    char tempAcc;

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
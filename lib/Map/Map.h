#pragma once

#include "../../inc/Global.h"
#include "../../inc/HitObject.h"
#include "../SoundManager/SoundManager.h"

class Map
{
    std::vector<HitObject *> hitObjects;

    SoundManager *music;

    unsigned int pausedTime;

    bool isPaused;

    unsigned int accuracyHits[4];
    unsigned int oldAcc;

    char tempAcc;

    unsigned int combo, highestCombo;

    unsigned int score;

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
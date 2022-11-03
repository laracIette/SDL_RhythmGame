#pragma once

#include "../../inc/Global.h"
#include "../../inc/HitObject.h"

class Map
{
    std::vector<HitObject *> hitObjects;

public:
    Map( std::string path );
    ~Map();

    void Update();
    void Draw();
};
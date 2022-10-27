#pragma once

#include "../../inc/Global.h"
#include "../../inc/HitObject.h"

class Map
{
    std::vector<HitObject> hitObjects;

public:
    Map( const char *path );
    ~Map();

    void Draw();
};
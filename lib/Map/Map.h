#pragma once

#include "../../inc/Global.h"
#include "../HitObject/HitObject.h"

class Map
{
    std::vector<HitObject> hitObjects;

public:
    Map( const char *path );
    ~Map();
};
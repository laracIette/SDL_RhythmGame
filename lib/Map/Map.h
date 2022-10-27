#pragma once

#include "../../inc/Global.h"
#include "../HitObject/HitObject.h"

class Map
{
    std::vector<HitObject> hitObjects;
    std::fstream file;

public:
    Map();
    ~Map();
};
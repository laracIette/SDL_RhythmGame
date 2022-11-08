#pragma once

#include "../Image/Image.h"

class Animation
{
    std::vector<Image *> images;
    unsigned int indice;
    unsigned int timeSinceLastImage;

public:
    Animation();
    ~Animation();

    void Draw();
};

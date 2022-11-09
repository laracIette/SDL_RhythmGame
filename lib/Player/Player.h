#pragma once

#include "../Image/Image.h"

class Player
{
    static const int nIMAGES{ 6 };

    Image *images[nIMAGES];
    bool isImageShown[nIMAGES]{ false };

    enum ImagesStates {
        HorizontalDefault = 0,
        UpLeft,
        UpRight,
        DownLeft,
        DownRight,
        VerticalDefault
    };

    bool isHorizontal;

public:
    Player();
    ~Player();

    void Input();
    void Draw();
};

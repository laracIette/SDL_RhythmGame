#pragma once

struct HitObject
{
    unsigned int time;
    bool isHit;

    unsigned char type;
};

struct Note : HitObject
{
    bool isUp;
};
struct Hold : HitObject
{
    unsigned int endTime;
    bool isUp;
};
struct Double : HitObject
{
};
struct Mash : HitObject
{
    unsigned int endTime;
};
struct Ghost : HitObject
{
    bool isUp;
};
struct Coin : HitObject
{
    bool isUp;
};
struct Hammer : HitObject
{
    bool isUp;
};
struct Chainsaw : HitObject
{
};
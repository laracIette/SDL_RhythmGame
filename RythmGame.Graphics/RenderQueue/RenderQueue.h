#pragma once

#include <vector>

#include "../RenderObject.h"

namespace RythmGame::Graphics
{

    enum Types {
        RenderSettings = 0,
        RenderStartScreen,
        RenderMapSelection,
        RenderGameplay
    };

    class RenderQueue
    {
        std::vector<RenderObject *> queue[4][10];

    public:
        RenderQueue();
        ~RenderQueue();

        void AddQueue( RenderObject *_object, int _type, int _index );

        void DrawQueue( int _type );
    };

    extern RenderQueue *renderQueue;

}
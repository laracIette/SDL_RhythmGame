#pragma once

#include <vector>

#include "../Renderable.h"

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
        std::vector<Renderable *> queue[4][10];

    public:
        RenderQueue();
        ~RenderQueue();

        void AddQueue( Renderable *_object, int _type, int _index );

        void ResetQueue();

        void ConvertType( int &_type );

        void DrawQueue( int _type );
    };

    extern RenderQueue *renderQueue;

}
#pragma once

#include <vector>

#include "../Renderable.h"

namespace RythmGame::Graphics
{

    enum Types {
        RenderSettings     = 0x00000001,
        RenderStartScreen  = 0x00000010,
        RenderMapSelection = 0x00000100,
        RenderGameplay     = 0x00001000
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
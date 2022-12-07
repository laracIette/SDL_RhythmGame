#include "RenderQueue.h"

namespace RythmGame::Graphics
{

    RenderQueue::RenderQueue()
    {
    }

    RenderQueue::~RenderQueue()
    {
    }

/**
 * @brief Add Renderable to queue[index]
 *
 * @param _object The Renderable * to render.
 * @param _type The type of the Renderable.
 * @param _priority The priority of the rendering, 0 highest to 9 lowest.
 */
    void RenderQueue::AddQueue( Renderable *_object, int _type, int _priority )
    {
        ConvertType( _type );

        queue[_type][_priority].push_back( _object );
    }

    void RenderQueue::ConvertType( int &_type )
    {
        switch( _type )
        {
        case RenderSettings:
            _type = 0;
            break;
        case RenderStartScreen:
            _type = 1;
            break;
        case RenderMapSelection:
            _type = 2;
            break;
        case RenderGameplay:
            _type = 3;
            break;
        default:
            _type = -1;
            break;
        }
    }


    void RenderQueue::ResetQueue()
    {
        for( int type{ 0 }; type < 4; ++type )
        {
            for( std::vector<Renderable *> &vec : queue[type] )
            {
                for( Renderable *object : vec )
                {
                    object->UnShow();
                }
            }
        }
    }


/**
 * @brief Render from queue[_type][0] to queue[_type][9].
 *        Renders from last added Renderable to first added.
 *
 * @param _type The type of the Renderable.
 */
    void RenderQueue::DrawQueue( int _type )
    {
        ConvertType( _type );

        for( int i{ 9 }; i >= 0; --i )
        {
            for( unsigned long j{ queue[_type][i].size() }; j > 0; --j )
            {
                if( queue[_type][i][j-1]->IsShown() ) queue[_type][i][j-1]->Draw();
            }
        }
    }


}
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
 * @brief Add SDL_Texture *, SDL_Rect to queue[index]
 *
 * @param _object The Renderable * to render.
 * @param _type The type of the Renderable.
 * @param _priority The priority of the rendering, 0 highest to 9 lowest.
 */
    void RenderQueue::AddQueue( Renderable *_object, int _type, int _priority )
    {
        _type = ConvertType( _type );

        queue[_type][_priority].push_back( _object );
    }

    int RenderQueue::ConvertType( int _type )
    {
        switch( _type )
        {
        case RenderSettings:
            return 0;
        case RenderStartScreen:
            return 1;
        case RenderMapSelection:
            return 2;
        case RenderGameplay:
            return 3;
        default:
            break;
        }

        return -1;
    }


    void RenderQueue::ResetQueue()
    {
        for( int type{ 0 }; type < 4; ++type )
        {
            for( std::vector<Renderable *> &vec : queue[type] )
            {
                for( Renderable *object : vec )
                {
                    object->IsShown( false );
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
        _type = ConvertType( _type );

        for( int i{ 9 }; i >= 0; --i )
        {
            for( unsigned long j{ queue[_type][i].size() }; j > 0; --j )
            {
                if( queue[_type][i][j-1]->IsShown() ) queue[_type][i][j-1]->Draw();
            }
        }
    }


}
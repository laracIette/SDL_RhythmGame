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
 * \brief Add SDL_Texture *, SDL_Rect to queue[index]
 *
 * \param _object The RenderObject * to render.
 * \param _type   The type of the rendering.
 * \param _index  The priority of the rendering, 0 highest to 9 lowest.
 */
    void RenderQueue::AddQueue( RenderObject *_object, int _type, int _index )
    {
        queue[_type][_index].push_back( _object );
    }


/**
 * \brief Render from queue[0] to queue[4]
 */
    void RenderQueue::DrawQueue( int _type )
    {
        for( int i{ 9 }; i >= 0; --i )
        {
            for( RenderObject *object : queue[_type][i] )
            {
                object->Draw();
            }
        }
    }


}
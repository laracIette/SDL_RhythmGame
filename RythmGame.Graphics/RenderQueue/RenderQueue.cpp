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
 * \param _tex    The SDL_Texture * to render.
 * \param _dest   The SDL_Rect & to render to.
 * \param _index  The priority of the texture rendering,
 *                0 highest to 4 lowest.
 */
    void RenderQueue::AddQueue( SDL_Texture *_tex, SDL_Rect &_dest, int _index )
    {
        queue[_index].push_back( {_tex, _dest} );
    }


/**
 * \brief Render from queue[0] to queue[4]
 */
    void RenderQueue::DrawRenderQueue()
    {
        for( std::vector<std::pair<SDL_Texture *, SDL_Rect &>> &vec : queue )
        {
            for( std::pair<SDL_Texture *, SDL_Rect &> &pair : vec )
            {
                TextureManager::DrawTexture( pair.first, pair.second );
            }
        }
    }

}
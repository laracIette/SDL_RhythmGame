#include <SDL.h>

#include "../inc/Metrics.h"
#include "../inc/Time.h"

#include "../lib/Game/Game.h"

unsigned int currentTime;
Game *game;

int WIDTH{ 1280 };
int HEIGHT{ 720 };

unsigned int FPS{ 60 };


int main( int argc, char *argv[] )
{
    unsigned int start;

    unsigned int i{ 1 };

    game = new Game();
    game->Init();

    start = currentTime;

    while( game->Running() )
    {
        currentTime = SDL_GetTicks();
        game->Update();

        if( (currentTime - start) > (1000 * i / FPS) )
        {
            game->Render();
            i++;
        }
        SDL_Delay( 1 );
    }

    game->Clear();

    return 0;
}
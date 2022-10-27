#include "../lib/Game/Game.h"

unsigned int currentTime;
Game *game;

int WIDTH{ 960 };
int HEIGHT{ 720 };

int main( int argc, char *argv[] )
{
    const int FPS{ 60 };

    unsigned int start;

    unsigned int i{ 1 };

    game = new Game();
    game->Init();

    start = currentTime;

    while( game->Running() )
    {
        getTime( currentTime );
        game->HandleEvents();
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
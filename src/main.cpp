#include "../includes.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game;

unsigned int RythmGame::Game::Utils::currentTime;

int RythmGame::Game::Utils::WIDTH{ 1280 };
int RythmGame::Game::Utils::HEIGHT{ 720 };

unsigned int RythmGame::Game::Utils::FPS{ 60 };

Run *run;


int main( int argc, char *argv[] )
{
    unsigned int start;

    unsigned int i{ 1 };

    run = new Run();
    run->Init();

    start = currentTime;

    while( run->Running() )
    {
        currentTime = SDL_GetTicks();
        run->Update();

        if( (currentTime - start) > (1000 * i / FPS) )
        {
            run->Render();
            i++;
        }
        SDL_Delay( 1 );
    }

    run->Clear();

    return 0;
}
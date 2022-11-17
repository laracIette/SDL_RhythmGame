#include <SDL.h>
#include <chrono>
#include <thread>

#include "../RythmGame.Game/Utils/Metrics.h"
#include "../RythmGame.Game/Utils/Time.h"

#include "../RythmGame.Game/Run/Run.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game;

std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::currentTime;
Run *run;

int RythmGame::Game::Utils::WIDTH{ 1280 };
int RythmGame::Game::Utils::HEIGHT{ 720 };

unsigned int RythmGame::Game::Utils::FPS{ 60 };


int main( int argc, char *argv[] )
{
    std::chrono::high_resolution_clock::time_point start;

    unsigned int i{ 1 };

    run = new Run();
    run->Init();

    start = currentTime;

    while( run->Running() )
    {
        currentTime = std::chrono::system_clock::now();

        run->Update();

        if( std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - start).count() > (1000 * i / FPS) )
        {
            run->Render();
            i++;
        }
        std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
    }

    run->Clear();

    return 0;
}
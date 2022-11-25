#include <SDL.h>
#include <chrono>
#include <thread>

#include "../RythmGame.Game/Utils/Metrics.h"
#include "../RythmGame.Game/Utils/Time.h"

#include "../RythmGame.Game/Run/Run.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game;

std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::currentTime;
std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::lastFrameTime;

Run *run;

int RythmGame::Game::Utils::WIDTH{ 1600 };
int RythmGame::Game::Utils::HEIGHT{ 900 };

int RythmGame::Game::Utils::FPS{ 60 };


int main( int argc, char *argv[] )
{
    std::chrono::high_resolution_clock::time_point start;

    unsigned long i{ 1 };

    run = new Run();
    run->Init();

    start = currentTime;

    while( run->Running() )
    {
        currentTime = std::chrono::system_clock::now();
        deltaTime = (float)getDuration<Milliseconds>( currentTime, lastFrameTime );
        lastFrameTime = currentTime;

        run->Update();

        if( getDuration<Microseconds>( currentTime, start ) > (1000000 * i / FPS) )
        {
            run->Render();
            i++;
        }
        std::this_thread::sleep_for( Milliseconds( 1 ) );
    }

    run->Clear();

    return 0;
}
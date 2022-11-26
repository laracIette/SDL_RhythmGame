#include <SDL.h>
#include <chrono>
#include <thread>
#include <iostream>

#include "../RythmGame.Game/Utils/Metrics.h"
#include "../RythmGame.Game/Utils/Time.h"
#include "../RythmGame.Game/Settings/SettingsFile.h"

#include "../RythmGame.Game/Run/Run.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game;
using namespace RythmGame::Game::Settings;

std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::currentTime;
std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::lastFrameTime;

Run *run;

SettingsFile *RythmGame::Game::Settings::settingsFile;

int RythmGame::Game::Utils::WIDTH;
int RythmGame::Game::Utils::HEIGHT;

int RythmGame::Game::Utils::FPS;


int main( int argc, char *argv[] )
{
    settingsFile = new SettingsFile();
    WIDTH  = settingsFile->FindValue<int>( "Dimension", "width" );
    HEIGHT = settingsFile->FindValue<int>( "Dimension", "height" );

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
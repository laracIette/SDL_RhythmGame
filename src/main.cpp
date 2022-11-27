#include <chrono>
#include <thread>
#include <iostream>


#include "../RythmGame.Framework/Window/Window.h"

#include "../RythmGame.Game/Utils/Metrics.h"
#include "../RythmGame.Game/Utils/Time.h"
#include "../RythmGame.Game/Settings/SettingsFile.h"

#include "../RythmGame.Game/Run/Run.h"


using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game;
using namespace RythmGame::Game::Settings;


RythmGame::Framework::Window *RythmGame::Framework::window;

std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::currentTime;
std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::lastFrameTime;

SettingsFile *RythmGame::Game::Settings::settingsFile;

int RythmGame::Game::Utils::WIDTH;
int RythmGame::Game::Utils::HEIGHT;
int RythmGame::Game::Utils::FPS;


int main( int argc, char *argv[] )
{
    settingsFile = new SettingsFile();

    WIDTH  = 1600;
    HEIGHT = 900;
    FPS    = 60;

    window = new RythmGame::Framework::Window();

    long images{ 1 };

    Run *run{ new Run() };
    run->Init();

    std::chrono::high_resolution_clock::time_point start{ currentTime };

    while( run->Running() )
    {
        currentTime   = std::chrono::system_clock::now();
        deltaTime     = (float)getDuration<Milliseconds>( currentTime, lastFrameTime );
        lastFrameTime = currentTime;

        run->Update();

        if( getDuration<Microseconds>( currentTime, start ) > (1000000 * images / FPS) )
        {
            run->Render();
            images++;
        }
        std::this_thread::sleep_for( Milliseconds( 1 ) );
    }

    run->Clear();

    return 0;
}
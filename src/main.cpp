#include <chrono>
#include <thread>
#include <iostream>


#include "../RythmGame.Framework/Window/Window.h"

#include "../RythmGame.Graphics/TextTTF/TextTTF.h"

#include "../RythmGame.Game/Utils/Metrics.h"
#include "../RythmGame.Game/Utils/Time.h"
#include "../RythmGame.Game/Settings/SettingsFile.h"
#include "../RythmGame.Game/Settings/Window.h"

#include "../RythmGame.Game/Run/Run.h"


using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game;
using namespace RythmGame::Game::Settings;
using namespace RythmGame::Graphics;


RythmGame::Framework::Window      *RythmGame::Framework::window;
RythmGame::Game::Settings::Window *RythmGame::Game::Settings::settingsWindow;

std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::currentTime;
std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::lastFrameTime;

SettingsFile *RythmGame::Game::Settings::settingsFile;

int RythmGame::Game::Utils::WIDTH;
int RythmGame::Game::Utils::HEIGHT;
int RythmGame::Game::Utils::FPS;

TTF_Font *RythmGame::Graphics::optionFont;
TTF_Font *RythmGame::Graphics::categoryTitleFont;


int main( int argc, char *argv[] )
{
    settingsFile   = new SettingsFile();
    settingsWindow = new RythmGame::Game::Settings::Window();

    WIDTH  = settingsWindow->GetWidth();
    HEIGHT = settingsWindow->GetHeight();
    FPS    = settingsWindow->GetFPS();

    window = new RythmGame::Framework::Window();

    optionFont        = TTF_OpenFont( "assets/UI/Fonts/OpenSans-Bold.ttf", resize( FONT_SIZE_OPTION ) );
    categoryTitleFont = TTF_OpenFont( "assets/UI/Fonts/OpenSans-Bold.ttf", resize( FONT_SIZE_CATEGORY_TITLE ) );

    settingsWindow->InitWindow();


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
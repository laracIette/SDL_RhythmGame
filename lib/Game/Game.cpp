#include "Game.h"

vec2<int> mouse;
unsigned int deltaTime;
Events events;
float velocity;

Window *window;

Game::Game()
{
    window = new Window();

    getTime( currentTime );

    isRunning = true;

    player = new Player();

    velocity = 0.2f;

    map = new Map( "assets/Maps/Plastic Smile - Kaori Ishihara/" );

    isStarted = false;
}

Game::~Game()
{
}

void Game::Init()
{
    deltaTime = 0;
}

void Game::Update()
{
    if( events.HandleEvents() ) isRunning = false;

    deltaTime = currentTime-lastFrameTime;
    lastFrameTime = currentTime;


    if( !isStarted && events.Pressed( events.keyboard.Space ) )
    {
        events.SetKeyLock( events.keyboard.Space, true );

        isStarted = true;
        map->Start();
    }
    if( isStarted
     && !events.KeyLock( events.keyboard.Space )
     && events.Pressed( events.keyboard.Space ) )
    {
        events.SetKeyLock( events.keyboard.Space, true );
        map->Pause();
    }

    player->Input();
    map->Update();
}


void Game::Render()
{
    SDL_RenderClear( window->renderer );

    player->Draw();
    map->Draw();

    SDL_RenderPresent( window->renderer );
}

void Game::Clear()
{
    SDL_DestroyWindow( window->window );
    SDL_DestroyRenderer( window->renderer );
    map->Close();
    Mix_CloseAudio();
    SDL_Quit();
}

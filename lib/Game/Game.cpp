#include "Game.h"
#include "../Map/Map.h"

vec2<int> mouse;
unsigned int deltaTime;

Window *window;

Events events;

Map *map;

Game::Game()
{
    window = new Window();

    getTime( currentTime );
    startTime = currentTime;

    isRunning = true;

    player = new Player();

    targets.push_back( new TargetUp() );
    newTargetLock = false;

    map = new Map( "assets/Maps/test0.txt" );
}

Game::~Game()
{
}

void Game::Init()
{
    deltaTime = 0;
}

void Game::HandleEvents()
{
    SDL_GetMouseState( &mouse.x, &mouse.y );

    while( SDL_PollEvent( &event ) )
    {
        switch( event.type )
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            for( int i{ 0 }; i < events.KEYS; ++i )
            {
                if( event.key.keysym.sym != events.keyCode[i] ) continue;

                events.keyPressed[i] = true;
                break;
            }
            break;

        case SDL_KEYUP:
            for( int i{ 0 }; i < events.KEYS; ++i )
            {
                if( event.key.keysym.sym != events.keyCode[i] ) continue;

                events.keyPressed[i] = false;
                break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
            for( int i{ 0 }; i < events.BUTTONS; ++i )
            {
                if( event.button.button != events.buttonCode[i] ) continue;

                events.buttonPressed[i] = true;
                break;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            for( int i{ 0 }; i < events.BUTTONS; ++i )
            {
                if( event.button.button != events.buttonCode[i] ) continue;

                events.buttonPressed[i] = false;
                break;
            }
            break;


        default:
            break;
        }
    }
}


void Game::Update()
{
    deltaTime = currentTime-lastFrameTime;
    lastFrameTime = currentTime;

    player->Input();

    for( Target *target : targets )
    {
        target->Move();
    }

    if( currentTime >= 5000 && !newTargetLock )
    {
        newTargetLock = true;
        targets.push_back( new TargetDown() );
    }

}


void Game::Render()
{
    SDL_RenderClear( window->renderer );

    player->Draw();

    for( Target *target : targets )
    {
        target->Draw();
    }

    SDL_RenderPresent( window->renderer );
}

void Game::Clear()
{
    SDL_DestroyWindow( window->window );
    SDL_DestroyRenderer( window->renderer );
    SDL_Quit();
}

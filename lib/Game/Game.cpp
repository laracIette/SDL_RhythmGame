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
            for( int i{ 0 }; i < events.keyboard.KEYS; ++i )
            {
                if( event.key.keysym.sym != events.keyboard.keyCode[i] ) continue;

                events.keyboard.keyPressed[i] = true;
                break;
            }
            break;

        case SDL_KEYUP:
            for( int i{ 0 }; i < events.keyboard.KEYS; ++i )
            {
                if( event.key.keysym.sym != events.keyboard.keyCode[i] ) continue;

                events.keyboard.keyPressed[i] = false;
                events.keyboard.keyLock[i] = false;
                break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
            for( int i{ 0 }; i < events.mouse.BUTTONS; ++i )
            {
                if( event.button.button != events.mouse.buttonCode[i] ) continue;

                events.mouse.buttonClicked[i] = true;
                break;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            for( int i{ 0 }; i < events.mouse.BUTTONS; ++i )
            {
                if( event.button.button != events.mouse.buttonCode[i] ) continue;

                events.mouse.buttonClicked[i] = false;
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

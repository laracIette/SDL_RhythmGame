#include "Run.h"


unsigned int RythmGame::Game::Utils::deltaTime;
unsigned int RythmGame::Game::Utils::offsetTime;

float RythmGame::Game::Utils::velocity;
bool  RythmGame::Game::Utils::isHorizontal;

Window *window;

InputManager inputManager;
HitSoundManager *hitSoundManager;


namespace RythmGame::Game
{

    Run::Run()
    {
        window = new Window();

        hitSoundManager = new HitSoundManager();

        currentTime = SDL_GetTicks();

        isRunning = true;

        player = new Player();

        velocity = 0.2f;

        map = new Map( "assets/Maps/Plastic Smile - Kaori Ishihara/" );

        isStarted = false;

        isHorizontal = true;

        startScreen = new Screen();
    }

    Run::~Run()
    {
    }

    void Run::Init()
    {
        deltaTime = 0;
        lastFrameTime = currentTime;
    }

    void Run::Update()
    {
        deltaTime = currentTime-lastFrameTime;
        lastFrameTime = currentTime;

        if( inputManager.HandleEvents() ) isRunning = false;

        if( !isStarted ) startScreen->Update();

        if( !isStarted && startScreen->PlayButtonClicked() )
        {
            isStarted = true;
            map->Start();
        }
        if( isStarted
         && !inputManager.KeyLock( inputManager.keyboard.Escape )
         && inputManager.Pressed( inputManager.keyboard.Escape ) )
        {
            inputManager.SetKeyLock( inputManager.keyboard.Escape, true );
            map->Pause();
        }

        player->Input();
        map->Update();
        hitSoundManager->Update();
    }


    void Run::Render()
    {
        SDL_SetRenderDrawColor( window->renderer, 48, 48, 48, 255 );
        SDL_RenderClear( window->renderer );

        player->Draw();
        map->Draw();

        if( !isStarted ) startScreen->Draw();

        SDL_RenderPresent( window->renderer );
    }

    void Run::Clear()
    {
        SDL_DestroyWindow( window->window );
        SDL_DestroyRenderer( window->renderer );
        map->Close();
        hitSoundManager->Close();
        Mix_CloseAudio();
        SDL_Quit();
    }

}
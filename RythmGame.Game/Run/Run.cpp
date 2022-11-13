#include "Run.h"

vec2<int> mouse;

unsigned int RythmGame::Game::Utils::deltaTime;
unsigned int RythmGame::Game::Utils::offsetTime;

float RythmGame::Game::Utils::velocity;
bool  RythmGame::Game::Utils::isHorizontal;

Window *window;

InputManager events;
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

        horizontalForeground = new Image(
            "assets/Skins/BaseSkin/foreground0.png",
            {0, 0, 1920, 1080},
            {(float)WIDTH/2, (float)HEIGHT/2, (float)WIDTH, (float)HEIGHT}
        );
        verticalForeground = new Image(
            "assets/Skins/BaseSkin/foreground1.png",
            {0, 0, 1920, 1080},
            {(float)WIDTH/2, (float)HEIGHT/2, (float)WIDTH, (float)HEIGHT}
        );
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
        if( events.HandleEvents() ) isRunning = false;

        deltaTime = currentTime-lastFrameTime;
        lastFrameTime = currentTime;


        if( !isStarted && events.Pressed( events.keyboard.Escape ) )
        {
            events.SetKeyLock( events.keyboard.Escape, true );

            isStarted = true;
            map->Start();
        }
        if( isStarted
        && !events.KeyLock( events.keyboard.Escape )
        && events.Pressed( events.keyboard.Escape ) )
        {
            events.SetKeyLock( events.keyboard.Escape, true );
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

        (isHorizontal) ? horizontalForeground->Draw() : verticalForeground->Draw();

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
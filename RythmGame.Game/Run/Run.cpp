#include "Run.h"

std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::offsetTime;

long RythmGame::Game::Utils::deltaTime;

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

        currentTime = std::chrono::system_clock::now();

        isRunning = true;

        player = new Player();

        velocity = 0.3f;

        isHorizontal = true;

        startScreen = new StartScreen::Screen();
        mapSelectionScreen = new MapSelection::Screen();
    }

    Run::~Run()
    {
    }

    void Run::Init()
    {
        deltaTime = 0;
        lastFrameTime = currentTime;

        gameState = STARTSCREEN;
    }

    void Run::Update()
    {

        if( inputManager.HandleEvents() ) isRunning = false;

        if( gameState == STARTSCREEN )
        {
            startScreen->Update();

            if( startScreen->StartGame() )
            {
                gameState = MAPSELECTION;
            }
        }

        if( gameState == MAPSELECTION )
        {
            Song *tempSong{ mapSelectionScreen->Update() };
            if( tempSong )
            {
                map = new Map( tempSong );
                map->Start();
                gameState = GAMEPLAY;
            }
        }

        if( gameState == GAMEPLAY )
        {
            if( inputManager.PressedNoLock( inputManager.keyboard.Escape ) )
            {
                inputManager.SetKeyLock( inputManager.keyboard.Escape, true );
                map->Pause();
            }

            player->Input();
            map->Update();
        }

        hitSoundManager->Update();
    }


    void Run::Render()
    {
        SDL_SetRenderDrawColor( window->renderer, 48, 48, 48, 255 );
        SDL_RenderClear( window->renderer );


        switch( gameState )
        {
        case STARTSCREEN:
            startScreen->Draw();
            break;

        case MAPSELECTION:
            mapSelectionScreen->Draw();
            break;

        case GAMEPLAY:
            player->Draw();
            map->Draw();
            break;

        default:
            break;
        }

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
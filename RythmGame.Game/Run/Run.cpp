#include "Run.h"


namespace RythmGame::Game
{
    Run::Run()
    {
        isRunning = true;

        startScreen = new StartScreen::Screen();

        mapSelectionScreen = new MapSelection::Screen();

        player = new Player();

        map = new Map();
    }

    Run::~Run()
    {
    }

    void Run::Init()
    {
        gameState = STARTSCREEN;

        isSettings = false;
    }

    void Run::Update()
    {

        if( inputManager->HandleEvents() ) isRunning = false;

        renderQueue->ResetQueue();

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
                map->Init( tempSong );
                map->Start();
                gameState = GAMEPLAY;
            }
        }
        if( gameState == GAMEPLAY )
        {
            if( inputManager->PressedNoLock( inputManager->keyboard.Escape ) )
            {
                inputManager->SetKeyLock( inputManager->keyboard.Escape, true );
                map->Pause();
            }

            player->Input();
            map->Update();
        }

        if( inputManager->PressedNoLock( inputManager->keyboard.S ) )
        {
            inputManager->SetKeyLock( inputManager->keyboard.S, true );

            isSettings = !isSettings;
        }

        if( isSettings )
        {
            settingsWindow->Scroll();
            settingsWindow->UpdateWindow();
        }


        if( inputManager->LeftClickedNoLock() )  inputManager->SetButtonLock( inputManager->mouse.Left,  true );
        if( inputManager->RightClickedNoLock() ) inputManager->SetButtonLock( inputManager->mouse.Right, true );

        hitSoundManager->Update();
        settingsFile->Update();
    }


    void Run::Render()
    {
        SDL_SetRenderDrawColor( window->renderer, 0, 0, 0, 255 );
        SDL_RenderClear( window->renderer );


        switch( gameState )
        {
        case STARTSCREEN:
            renderQueue->DrawQueue( RenderStartScreen );
            break;

        case MAPSELECTION:
            renderQueue->DrawQueue( RenderMapSelection );
            break;

        case GAMEPLAY:
            renderQueue->DrawQueue( RenderGameplay );
            break;

        default:
            break;
        }

        if( isSettings )
        {
            renderQueue->DrawQueue( RenderSettings );
        }


        SDL_RenderPresent( window->renderer );
    }

    void Run::Clear()
    {
        map->Close();
        hitSoundManager->Close();
        TTF_CloseFont( optionFont );
        TTF_CloseFont( categoryTitleFont );
        TTF_Quit();
        Mix_CloseAudio();
        SDL_DestroyWindow( window->window );
        SDL_DestroyRenderer( window->renderer );
        SDL_Quit();
    }

}
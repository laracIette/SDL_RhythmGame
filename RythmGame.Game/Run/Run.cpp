#include "Run.h"

std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::offsetTime;

long  RythmGame::Game::Utils::deltaTime;
float RythmGame::Game::Utils::velocity;
bool  RythmGame::Game::Utils::isHorizontal;

Window *RythmGame::Framework::window;

InputManager RythmGame::Game::Events::inputManager;

HitSoundManager *RythmGame::Sound::hitSoundManager;

TTF_Font *RythmGame::Graphics::optionFont;
TTF_Font *RythmGame::Graphics::categoryTitleFont;

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

        optionFont = TTF_OpenFont( "assets/Fonts/Ronysiswadi9Bold.ttf", 24 );
        categoryTitleFont = TTF_OpenFont( "assets/Fonts/Ronysiswadi9Bold.ttf", 30 );

        settingsWindow = new Settings::Window();
        isSettings = false;

        map = new Map();
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
                map->Init( tempSong );
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

        if( inputManager.PressedNoLock( inputManager.keyboard.S ) )
        {
            inputManager.SetKeyLock( inputManager.keyboard.S, true );

            isSettings = (isSettings) ? false : true;
        }

        if( isSettings )
        {
            settingsWindow->Update();
        }

        hitSoundManager->Update();
    }


    void Run::Render()
    {
        GPU_Clear( window->renderer );

        switch( gameState )
        {
        case STARTSCREEN:
            startScreen->Draw();
            break;

        case MAPSELECTION:
            mapSelectionScreen->Draw();
            break;

        case GAMEPLAY:
            map->Draw();
            player->Draw();
            break;

        default:
            break;
        }

        if( isSettings )
        {
            settingsWindow->Draw();
        }

        GPU_Flip( window->renderer );
    }

    void Run::Clear()
    {
        TTF_CloseFont( optionFont );
        TTF_Quit();
        map->Close();
        hitSoundManager->Close();
        Mix_CloseAudio();
        SDL_Quit();
    }

}
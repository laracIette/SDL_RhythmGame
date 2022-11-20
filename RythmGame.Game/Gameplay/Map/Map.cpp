#include "Map.h"

namespace RythmGame::Game::Gameplay
{

    Map::Map( std::string path )
    {
        song = new Song( path );

        for( HitObject *hitObject : song->GetHitObjects() )
        {
            hitObject->Init();
        }

        isPaused = true;

        music = new Music( path + "song.mp3" );

        score    = new Score();
        combo    = new Combo();
        accuracy = new Accuracy();

        dim = new Dim();


    }

    Map::~Map()
    {
    }

    void Map::Start()
    {
        isPaused = false;

        offsetTime = currentTime;

        score->SetScore( 0 );
        combo->SetCombo( 0 );

        highestCombo = 0;

        music->SetVolume( 0 );
        music->Play();
    }

    void Map::Update()
    {
        if( isPaused ) return;

        int j{ 0 };
        for( int i{ 0 }; i < song->GetHitObjects().size(); ++i )
        {
            song->GetHitObjects()[j]->Update();

            if( (song->GetHitObjects()[j]->type == CHAINSAW) && song->GetHitObjects()[j]->IsHit() )
            {
                combo->SetCombo( 0 );
                std::cout << "hit" << std::endl;
            }

            tempAcc = song->GetHitObjects()[j]->GetHitValue();

            if( tempAcc == 0 )      score->AddScore( 300 );
            else if( tempAcc == 1 ) score->AddScore( 100 );
            else if( tempAcc == 2 ) score->AddScore( 50 );

            if( (tempAcc >= 0) && (tempAcc <= 3) && (song->GetHitObjects()[j]->type != COIN) )
            {
                accuracy->AddValue( tempAcc );
                combo->AddCombo();
            }
            else if( (tempAcc == 25) && (song->GetHitObjects()[j]->type == COIN) )
            {
                score->AddScore( 25 );
            }
            else if( (tempAcc == 10) && (song->GetHitObjects()[j]->type == MASH) )
            {
                score->AddScore( 10 );
            }

            if( song->GetHitObjects()[j]->Erase() )
            {
                if( !song->GetHitObjects()[j]->IsHit() && (song->GetHitObjects()[j]->type != COIN) && (song->GetHitObjects()[j]->type != CHAINSAW) )
                {
                    combo->SetCombo( 0 );
                    accuracy->AddValue( 3 );
                }
                song->GetHitObjects().erase( song->GetHitObjects().begin() + j-- );
            }

            j++;

            if( combo->GetCombo() > highestCombo ) highestCombo = combo->GetCombo();
        }

        accuracy->Update();

    }

    void Map::Draw()
    {
        for( HitObject *hitObject : song->GetHitObjects() )
        {
            hitObject->DrawHitObject();
        }

        (isHorizontal) ? dim->DrawHorizontalDim() : dim->DrawVerticalDim();

        score->Draw();
        combo->Draw();
        accuracy->Draw();
    }

    void Map::Pause()
    {
        if( !isPaused )
        {
            isPaused = true;
            pausedTime = currentTime;

            music->Pause();
        }
        else
        {
            isPaused = false;

            offsetTime += currentTime - pausedTime;

            music->Resume();
        }
    }

    void Map::Close()
    {
        music->Close();
    }

}
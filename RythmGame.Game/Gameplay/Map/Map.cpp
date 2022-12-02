#include "Map.h"

namespace RythmGame::Game::Gameplay
{

    Map::Map()
    {
        isPaused = true;

        score    = new Score();
        combo    = new Combo();
        accuracy = new Accuracy();

        dim = new Dim();

        isInit = false;
    }

    Map::~Map()
    {
    }

    void Map::Init( Song *newSong )
    {
        isInit = true;

        song = newSong;
        song->FillHitObjects();

        for( HitObject *hitObject : song->GetHitObjects() )
        {
            hitObject->Init();
        }

        song->GetBackground()->SetX( 1920/2 );
        song->GetBackground()->SetY( 1080/2 );
        song->GetBackground()->SetW( 1920 );
        song->GetBackground()->SetH( 1080 );
    }

    void Map::Start()
    {
        isPaused = false;

        offsetTime = currentTime;

        score->SetScore( 0 );
        combo->SetCombo( 0 );

        highestCombo = 0;

        song->GetMusic()->SetVolume( 1 );
        song->GetMusic()->Play();
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

        song->GetBackground()->IsShown( true );

        (isHorizontal) ? dim->ShowHorizontalDim() : dim->ShowVerticalDim();

        score->IsShown( true );
        combo->IsShown( true );
        accuracy->IsShown( true );

    }

    void Map::Pause()
    {
        if( !isPaused )
        {
            isPaused = true;
            pausedTime = currentTime;

            song->GetMusic()->Pause();
        }
        else
        {
            isPaused = false;

            offsetTime += currentTime - pausedTime;

            song->GetMusic()->Resume();
        }
    }

    void Map::Close()
    {
        if( isInit )
        {
            song->GetMusic()->Close();
        }
    }

}
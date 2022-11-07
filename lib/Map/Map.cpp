#include "Map.h"

Map::Map( std::string path )
{
    std::ifstream file( path + "easy.txt" );
    std::string temp;
    std::string nTemp;

    unsigned char nSteps;

    while( getline( file, temp ) )
    {
        nSteps = 0;
        switch( temp[0] - '0' )
        {
        case NOTE:
        {
            Note *noteTemp{ new Note() };
            noteTemp->type = NOTE;
            noteTemp->direction = temp[2];

            for( int i{ 4 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp += temp[i];
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        noteTemp->time = std::stoi( nTemp );
                        break;

                    case 1:
                        noteTemp->isUp = std::stoi( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            hitObjects.push_back( noteTemp );
            break;
        }

        case HOLD:
        {
            Hold *holdTemp{ new Hold() };
            holdTemp->type = HOLD;
            holdTemp->direction = temp[2];

            for( int i{ 4 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp += temp[i];
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        holdTemp->time = std::stoi( nTemp );
                        break;

                    case 1:
                        holdTemp->isUp = std::stoi( nTemp );
                        break;

                    case 2:
                        holdTemp->endTime = std::stoi( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            hitObjects.push_back( holdTemp );
            break;
        }

        case DOUBLE:
        {
            Double *doubleTemp{ new Double() };
            doubleTemp->type = DOUBLE;
            doubleTemp->direction = temp[2];

            for( int i{ 4 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp += temp[i];
                }
                else
                {
                    doubleTemp->time = std::stoi( nTemp );

                    nTemp.clear();
                }
            }
            hitObjects.push_back( doubleTemp );
            break;
        }

        case MASH:
        {
            Mash *mashTemp{ new Mash() };
            mashTemp->type = MASH;
            mashTemp->direction = temp[2];

            for( int i{ 4 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp += temp[i];
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        mashTemp->time = std::stoi( nTemp );
                        break;

                    case 1:
                        mashTemp->endTime = std::stoi( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            hitObjects.push_back( mashTemp );
            break;
        }

        case GHOST:
        {
            Ghost *ghostTemp{ new Ghost() };
            ghostTemp->type = GHOST;
            ghostTemp->direction = temp[2];

            for( int i{ 4 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp += temp[i];
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        ghostTemp->time = std::stoi( nTemp );
                        break;

                    case 1:
                        ghostTemp->isUp = std::stoi( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            hitObjects.push_back( ghostTemp );
            break;
        }

        case COIN:
        {
            Coin *coinTemp{ new Coin() };
            coinTemp->type = COIN;
            coinTemp->direction = temp[2];

            for( int i{ 4 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp += temp[i];
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        coinTemp->time = std::stoi( nTemp );
                        break;

                    case 1:
                        coinTemp->isUp = std::stoi( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            hitObjects.push_back( coinTemp );
            break;
        }

        case HAMMER:
        {
            Hammer *hammerTemp{ new Hammer() };
            hammerTemp->type = HAMMER;
            hammerTemp->direction = temp[2];

            for( int i{ 4 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp += temp[i];
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        hammerTemp->time = std::stoi( nTemp );
                        break;

                    case 1:
                        hammerTemp->isUp = std::stoi( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            hitObjects.push_back( hammerTemp );
            break;
        }

        case CHAINSAW:
        {
            Chainsaw *chainsawTemp{ new Chainsaw() };
            chainsawTemp->type = CHAINSAW;
            chainsawTemp->direction = temp[2];

            for( int i{ 4 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp += temp[i];
                }
                else
                {
                    chainsawTemp->time = std::stoi( nTemp );

                    nTemp.clear();
                }
            }
            hitObjects.push_back( chainsawTemp );
            break;
        }

        default:
            break;
        }
    }

    file.close();

    for( HitObject *hitObject : hitObjects )
    {
        hitObject->Init();
    }

    isPaused = true;

    music = new SoundManager( path + "song.mp3" );

    oldAcc = 0;

    for( unsigned int &acc : accuracyHits ) acc = 0;
}

Map::~Map()
{
}

void Map::Update()
{
    if( isPaused ) return;

    int j{ 0 };
    for( int i{ 0 }; i < hitObjects.size(); ++i )
    {
        hitObjects[j]->Update();

        if( (hitObjects[j]->type == CHAINSAW) && hitObjects[j]->IsHit() ) CoutEndl("hit")

        tempAcc = hitObjects[j]->GetHitValue();

        if( tempAcc != -1 && (hitObjects[j]->type != COIN) ) accuracyHits[tempAcc]++;
        else if( tempAcc == HitAccuracy::Perfect && (hitObjects[j]->type == COIN) ) CoutEndl("coin")

        if( hitObjects[j]->Erase() )
        {
            if( !hitObjects[j]->IsHit() && (hitObjects[j]->type != COIN) && (hitObjects[j]->type != CHAINSAW) )
            {
                accuracyHits[3]++;
            }
            hitObjects.erase( hitObjects.begin() + j-- );
        }

        j++;
    }

    if( accuracyHits[0] + accuracyHits[1] + accuracyHits[2] + accuracyHits[3] != oldAcc )
    {
        oldAcc = accuracyHits[0] + accuracyHits[1] + accuracyHits[2] + accuracyHits[3];
        CoutEndl(accuracyHits[0] << ' ' << accuracyHits[1] << ' ' << accuracyHits[2] << ' ' << accuracyHits[3] << ';' << GetAccuracy())
    }
}

void Map::Draw()
{
    for( HitObject *hitObject : hitObjects )
    {
        hitObject->Draw();
    }
}

void Map::Start()
{
    isPaused = false;
    for( HitObject *hitObject : hitObjects )
    {
        hitObject->offsetTime = currentTime;
    }

    music->SetVolume( 1 );
    music->Play();
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
        for( HitObject *hitObject : hitObjects )
        {
            hitObject->offsetTime += currentTime - pausedTime;
        }

        music->Resume();
    }
}

void Map::Close()
{
    music->Close();
}

float Map::GetAccuracy()
{
    if( accuracyHits[0] + accuracyHits[1] + accuracyHits[2] + accuracyHits[3] == 0 ) return 100;

    if( accuracyHits[0] + accuracyHits[1] + accuracyHits[2] == 0 ) return 0;

    return 100 * (float)(6*accuracyHits[0] + 2*accuracyHits[1] + accuracyHits[2]) / (float)(6*(accuracyHits[0] + accuracyHits[1] + accuracyHits[2] + accuracyHits[3]));
}
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
        hitObject->isHit = false;
        hitObject->isShown = false;
        hitObject->offsetTime = 0;
        hitObject->Init();
    }

    isPaused = true;

    music = new SoundManager( path + "song.mp3" );
}

Map::~Map()
{
}

void Map::Update()
{
    if( isPaused ) return;

    for( HitObject *hitObject : hitObjects )
    {
        hitObject->Update();
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

    music->SetVolume( 10 );
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
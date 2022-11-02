#include "Map.h"

Map::Map( const char *path )
{
    std::ifstream file( path );
    std::string temp;
    std::vector<char> nTemp;

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
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        noteTemp->time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        noteTemp->isUp = strTo<bool>( nTemp );
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
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        holdTemp->time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        holdTemp->isUp = strTo<bool>( nTemp );
                        break;

                    case 2:
                        holdTemp->endTime = strTo<unsigned int>( nTemp );
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
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    doubleTemp->time = strTo<unsigned int>( nTemp );

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
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        mashTemp->time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        mashTemp->endTime = strTo<unsigned int>( nTemp );
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
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        ghostTemp->time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        ghostTemp->isUp = strTo<bool>( nTemp );
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
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        coinTemp->time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        coinTemp->isUp = strTo<bool>( nTemp );
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
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    switch( nSteps )
                    {
                    case 0:
                        hammerTemp->time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        hammerTemp->isUp = strTo<bool>( nTemp );
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
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    chainsawTemp->time = strTo<unsigned int>( nTemp );

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

    for( HitObject *hitObject : hitObjects )
    {
        hitObject->isHit = false;
        hitObject->isShown = false;
        hitObject->Init();
        //std::cout << hitObject->direction << ' '
        //          << hitObject->isHit << ' '
        //          << hitObject->time << ' '
        //          << hitObject->type << std::endl;
    }

}

Map::~Map()
{
}

void Map::Update()
{
    for( HitObject *hitObject : hitObjects )
    {
        hitObject->Move();
    }
}

void Map::Draw()
{
    for( HitObject *hitObject : hitObjects )
    {
        hitObject->Draw();
    }
}
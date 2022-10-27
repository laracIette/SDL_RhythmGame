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
            Note noteTemp;
            noteTemp.type = NOTE;

            for( int i{ 2 }; i < temp.size(); ++i )
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
                        noteTemp.time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        noteTemp.isUp = strTo<bool>( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            break;

        case HOLD:
            Hold holdTemp;
            holdTemp.type = HOLD;

            for( int i{ 2 }; i < temp.size(); ++i )
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
                        holdTemp.time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        holdTemp.isUp = strTo<bool>( nTemp );
                        break;

                    case 2:
                        holdTemp.endTime = strTo<unsigned int>( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            break;

        case DOUBLE:
            Double doubleTemp;
            doubleTemp.type = DOUBLE;

            for( int i{ 2 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    doubleTemp.time = strTo<unsigned int>( nTemp );

                    nTemp.clear();
                }
            }
            break;

        case MASH:
            Mash mashTemp;
            mashTemp.type = MASH;

            for( int i{ 2 }; i < temp.size(); ++i )
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
                        mashTemp.time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        mashTemp.endTime = strTo<unsigned int>( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            break;

        case GHOST:
            Ghost ghostTemp;
            ghostTemp.type = GHOST;

            for( int i{ 2 }; i < temp.size(); ++i )
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
                        ghostTemp.time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        ghostTemp.isUp = strTo<bool>( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            break;

        case COIN:
            Coin coinTemp;
            coinTemp.type = COIN;

            for( int i{ 2 }; i < temp.size(); ++i )
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
                        coinTemp.time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        coinTemp.isUp = strTo<bool>( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            break;

        case HAMMER:
            Hammer hammerTemp;
            hammerTemp.type = HAMMER;

            for( int i{ 2 }; i < temp.size(); ++i )
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
                        hammerTemp.time = strTo<unsigned int>( nTemp );
                        break;

                    case 1:
                        hammerTemp.isUp = strTo<bool>( nTemp );
                        break;

                    default:
                        break;
                    }
                    nTemp.clear();
                    nSteps++;
                }
            }
            break;

        case CHAINSAW:
            Chainsaw chainsawTemp;
            chainsawTemp.type = CHAINSAW;

            for( int i{ 2 }; i < temp.size(); ++i )
            {
                if( (temp[i] != ';') )
                {
                    nTemp.push_back( temp[i] );
                }
                else
                {
                    chainsawTemp.time = strTo<unsigned int>( nTemp );

                    nTemp.clear();
                }
            }
            break;

        default:
            break;
        }
    }

    for( HitObject hitObject : hitObjects )
    {
        hitObject.isHit = false;
    }
}

Map::~Map()
{
}

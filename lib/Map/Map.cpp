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
            noteTemp.type  = NOTE;
            noteTemp.isHit = false;

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
            break;

        case DOUBLE:
            break;

        case MASH:
            break;

        case GHOST:
            break;

        case COIN:
            break;

        case HAMMER:
            break;

        case CHAINSAW:
            break;

        default:
            break;
        }
    }
}

Map::~Map()
{
}

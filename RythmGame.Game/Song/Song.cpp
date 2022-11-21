#include "Song.h"

namespace RythmGame::Game
{

    Song::Song( std::string path )
    {
        songFile = new File( path + "/easy.txt" );

        name       = songFile->GetSingleElements()["Name"];
        author     = songFile->GetSingleElements()["Author"];
        difficulty = songFile->GetSingleElements()["Difficulty"];
        level      = std::stof( songFile->GetSingleElements()["Level"] );

        background = new Background(
            path + "/background.png",
            {0, 0, 1920, 1080}
        );

        music = new Music( path + "/song.mp3" );
    }

    Song::~Song()
    {
    }

    void Song::FillHitObjects()
    {
        std::string nTemp;
        int nSteps;

        for( std::string temp : songFile->GetMultiElements()["HitObjects"] )
        {
            HitObject *hitObject;

            nSteps = 0;
            switch( temp[0] - '0' )
            {
            case NOTE:
            {
                hitObject = new Note();

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
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case HOLD:
            {
                hitObject = new Hold();

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
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        case 2:
                            hitObject->endTime = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case DOUBLE:
            {
                hitObject = new Double();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        hitObject->time = std::stoi( nTemp );

                        nTemp.clear();
                    }
                }
                break;
            }

            case MASH:
            {
                hitObject = new Mash();

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
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->endTime = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case GHOST:
            {
                hitObject = new Ghost();

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
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case COIN:
            {
                hitObject = new Coin();

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
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case HAMMER:
            {
                hitObject = new Hammer();

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
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case CHAINSAW:
            {
                hitObject = new Chainsaw();

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
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            default:
            /* create error type (maybe) */
                break;
            }

            hitObject->type      = temp[0]-'0';
            hitObject->direction = temp[2]-'0';

            hitObjects.push_back( hitObject );
        }
    }

    float Song::GetLevel()
    {
        return level;
    }

    Image *Song::GetBackground()
    {
        return background;
    }

    std::vector<HitObject *> &Song::GetHitObjects()
    {
        return hitObjects;
    }

    Music *Song::GetMusic()
    {
        return music;
    }

}

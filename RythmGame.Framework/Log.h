#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>


namespace RythmGame::Framework
{

    static std::string removeSkipLine( std::string _text )
    {
        std::string newText;
        for( int i{ 0 }; i < _text.size(); ++i )
        {
            if( _text[i] != '\n' ) newText += _text[i];
        }
        return newText;
    }

    class Log
    {
        std::fstream file;

    public:
        Log() {}
        ~Log() {}

        void Write( std::string _text )
        {
            time_t now = time( 0 );

            file.open( "assets/log.txt", std::ios::app );
            if( !file.is_open() )
            {
                std::cout << "File error, couldn't open 'assets/log.txt'" << std::endl;
            }
            else
            {
                file << std::string( "[" + removeSkipLine( ctime( &now ) ) + "] " + _text + "\n" );
                file.close();
            }
        }
    };

    extern Log *logFile;

}

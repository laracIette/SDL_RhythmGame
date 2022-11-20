#include "File.h"

namespace RythmGame::Framework
{

    File::File( std::string path )
    {
        std::ifstream file( path );
        if( !file ) std::cout << "file error, couldn't open '" << path << "'" << std::endl;

        std::string temp;
        std::string keyTemp;
        std::string valueTemp;

        std::vector<std::string> multiElementsValues;

        bool isValueTempStarted{ false };
        bool isMultiElements{ false };

        int colonIndice;

        while( getline( file, temp ) )
        {
            if( temp != "" ) lines.push_back( temp );
        }

        for( std::string line : lines )
        {
            if( line[0] == '[' )
            {
                keyTemp = "";
                multiElementsValues.clear();
                isMultiElements = true;
                for( int i{ 1 }; i < line.size()-1; ++i )
                {
                    keyTemp += line[i];
                }
                continue;
            }

            if( isMultiElements )
            {
                if( line == "~/.end" )
                {
                    isMultiElements = false;
                    multiElements[keyTemp] = multiElementsValues;
                }
                else
                {
                    multiElementsValues.push_back( line );
                }
                continue;
            }

            keyTemp = "";
            valueTemp = "";
            isValueTempStarted = false;

            colonIndice = -1;

            for( int i{ 0 }; i < line.size(); ++i )
            {
                if( line[i] == ':' )
                {
                    colonIndice = i;
                }
            }

            if( colonIndice == -1 ) continue;

            for( int i{ 0 }; i < colonIndice; ++i )
            {
                if( line[i] != ' ' )
                {
                    keyTemp += line[i];
                }
            }

            for( int i{ colonIndice + 1 }; i < line.size(); ++i )
            {
                if( (line[i] == ' ') && !isValueTempStarted ) continue;

                valueTemp += line[i];
                isValueTempStarted = true;
            }

            singleElements[keyTemp] = valueTemp;
        }

        file.close();
    }

    File::~File()
    {
    }

    std::map<std::string, std::string> &File::GetSingleElements()
    {
        return singleElements;
    }
    std::map<std::string, std::vector<std::string>> &File::GetMultiElements()
    {
        return multiElements;
    }
}

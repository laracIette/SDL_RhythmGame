#pragma once

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>

namespace RythmGame::Framework
{

    class File
    {
        std::vector<std::string> lines;

        std::map<std::string, std::string> singleElements;
        std::map<std::string, std::vector<std::string>> multiElements;

    public:
        File( std::string path );
        ~File();

        std::map<std::string, std::string> &GetSingleElements();
        std::map<std::string, std::vector<std::string>> &GetMultiElements();
    };

}


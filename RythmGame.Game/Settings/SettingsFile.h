#pragma once

#include "../../inc/json.hpp"
#include <fstream>
#include <iostream>


namespace RythmGame::Game::Settings
{

    class SettingsFile
    {

    public:
        nlohmann::json data;
        bool isWriteData;

        SettingsFile()
        {
            std::ifstream file( "assets/Settings.json" );
            data = nlohmann::json::parse( file );
            file.close();

            isWriteData = false;
        }
        ~SettingsFile() {}

        void Update()
        {
            if( isWriteData )
            {
                isWriteData = false;

                std::ofstream output( "assets/Settings.json" );
                output << std::setw(4) << data << std::endl;
                output.close();

                std::cout << "Settings File written" << std::endl;
            }
        }

    };

    extern SettingsFile *settingsFile;

}
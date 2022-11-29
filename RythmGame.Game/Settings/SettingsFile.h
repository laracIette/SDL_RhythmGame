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
        bool writeData;

        SettingsFile()
        {
            std::ifstream file( "assets/Settings.json" );
            data = nlohmann::json::parse( file );
            file.close();

            writeData = false;
        }
        ~SettingsFile() {}

        void Update()
        {
            if( writeData )
            {
                writeData = false;

                std::ofstream output( "assets/Settings.json" );
                output << std::setw(4) << data << std::endl;
                output.close();
            }
        }

    };

    extern SettingsFile *settingsFile;

}
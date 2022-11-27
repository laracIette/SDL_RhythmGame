#pragma once

#include <json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

namespace RythmGame::Game::Settings
{

    class SettingsFile
    {

    public:
        json data;
        bool writeData;

        SettingsFile()
        {
            std::ifstream file( "assets/Settings.json" );
            data = json::parse( file );
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
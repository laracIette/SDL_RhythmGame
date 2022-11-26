#pragma once

#include <json.hpp>
#include <fstream>
#include <string>

using json = nlohmann::json;

namespace RythmGame::Game::Settings
{

    class SettingsFile
    {

    public:
        json data;

        SettingsFile()
        {
            std::ifstream file( "assets/Settings.json" );
            data = json::parse( file );
            file.close();
        }
        ~SettingsFile() {}

        template<typename T>
        T FindValue( std::string key, std::string valueName = "value" )
        {
            T ret;
            for( auto category : data["settings"] )
            {
                for( auto option : category["options"] )
                {
                    if( option["name"] == key )
                    {
                        return option[valueName];
                    }
                }
            }
            return ret;
        }
        template<typename T>
        void ChangeValue( std::string key, T newValue )
        {
            for( auto &category : data["settings"] )
            {
                for( auto &option : category["options"] )
                {
                    if( option["name"] == key )
                    {
                        option["value"] = newValue;
                        return;
                    }
                }
            }
        }
    };

    extern SettingsFile *settingsFile;

}
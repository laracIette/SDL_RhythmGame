#include "Window.h"

namespace RythmGame::Game::Settings
{

    Window::Window()
    {

        for( auto category : settingsFile->data["settings"] )
        {
            std::vector<OptionTemplate *> tempOptionsVector;

            for( auto option : category["options"] )
            {
                OptionTemplate *tempOption;

                if( option["type"] == "Value" )
                {
                    tempOption = new Value(
                        option["name"],
                        option["value"]
                    );
                }
                else if( option["type"] == "Slider" )
                {
                    tempOption = new Slider(
                        option["name"],
                        option["value"],
                        option["value.min"],
                        option["value.max"]
                    );
                }
                else if( option["type"] == "Check" )
                {
                    tempOption = new Check(
                        option["name"],
                        option["value"]
                    );
                }
                else if( option["type"] == "Options" )
                {
                    tempOption = new Options(
                        option["name"],
                        option["value"],
                        option["value.options"]
                    );
                }

                if( tempOption )
                {
                    tempOptionsVector.push_back( tempOption );
                }
            }

            categories.push_back(
                new Category(
                    category["name"],
                    tempOptionsVector
                )
            );

        }

        backgroundRect.x = 0;
        backgroundRect.y = 0;
        backgroundRect.w = resize( 1920/3 );
        backgroundRect.h = resize( 1080 );

        backgroundColor = {69, 69, 69};

        posY = 0;

    }

    Window::~Window()
    {
    }

    void Window::Update()
    {
        if( (posY + inputManager.WheelMovementY()) >= 0 )
        {
            posY += inputManager.WheelMovementY();
        }

        std::map<std::string, float> tempToChange;

        int tempPosY{ (int)posY };
        for( Category *category : categories )
        {
            tempPosY = category->Update( tempPosY ) + 50;

            for( std::pair<std::string, float> tempPair : category->ChangeValue() )
            {
                tempToChange[tempPair.first] = tempPair.second;
            }
        }

        bool updateJsonFile{ false };
        for( auto &category : settingsFile->data["settings"] )
        {
            for( auto &option : category["options"] )
            {
                for( std::pair<std::string, float> tempPair : tempToChange )
                {
                    if( option["name"] == tempPair.first )
                    {
                        updateJsonFile = true;
                        if( option["type"] == "Check" )
                        {
                            option["value"] = (bool)tempPair.second;
                        }
                        else
                        {
                            option["value"] = tempPair.second;
                        }
                    }
                }
            }
        }
        if( updateJsonFile )
        {
            std::ofstream o( "assets/Settings.json" );
            o << std::setw(4) << settingsFile->data << std::endl;
            o.close();
        }
    }

    void Window::Draw()
    {
        window->FillRectangle( backgroundRect, backgroundColor );

        for( Category *category : categories )
        {
            category->Draw();
        }

    }
}
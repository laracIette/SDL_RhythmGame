#include "Window.h"

namespace RythmGame::Game::Settings
{

    Window::Window()
    {
        std::ifstream file( "assets/Settings.json" );
        data = json::parse( file );
        file.close();

        for( auto category : data["settings"] )
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
                        option["options"]
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

        backgroundRect = new SDL_Rect();

        backgroundRect->x = 0;
        backgroundRect->y = 0;
        backgroundRect->w = resize( 1920/3 );
        backgroundRect->h = resize( 1080 );

        backgroundColor = {69, 69, 69};

        posY = 0;
    }

    Window::~Window()
    {
    }

    void Window::Update()
    {
        posY += inputManager.WheelMovementY();

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

        for( auto &category : data["settings"] )
        {
            for( auto &option : category["options"] )
            {
                for( std::pair<std::string, float> tempPair : tempToChange )
                {
                    if( option["name"] == tempPair.first )
                    {
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
        std::ofstream o( "assets/Settings.json" );
        o << std::setw(4) << data << std::endl;
        o.close();
    }

    void Window::Draw()
    {
        window->DrawRectangle( backgroundRect, backgroundColor );

        for( Category *category : categories )
        {
            category->Draw();
        }
    }
}
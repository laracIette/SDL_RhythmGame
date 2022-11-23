#include "Window.h"

namespace RythmGame::Game::Settings
{

    Window::Window()
    {
        std::ifstream file( "assets/Settings.json" );
        json data = json::parse( file );

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
                        option["min"],
                        option["max"]
                    );
                }
                else if( option["type"] == "Check" )
                {
                    tempOption = new Check(
                        option["name"],
                        option["value"]
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
    }

    Window::~Window()
    {
    }

    void Window::Update()
    {
        int posY{ 0 };
        for( Category *category : categories )
        {
            posY = category->Update( posY ) + 50;
        }
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
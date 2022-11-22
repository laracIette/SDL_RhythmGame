#include "Window.h"

namespace RythmGame::Game::Settings
{

    Window::Window()
    {
        categories.push_back(
            new Category(
                "Salutations",
                {
                    "Yo !",
                    "GG"
                }
            )
        );
        categories.push_back(
            new Category(
                "LOOOL",
                {
                    "ppoypoop !",
                    "ffd",
                    "9403T3/UJ"
                }
            )
        );

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
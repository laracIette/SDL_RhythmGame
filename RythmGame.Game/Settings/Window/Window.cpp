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
    }

    Window::~Window()
    {
    }

    void Window::Update()
    {
        int posY{ 0 };
        for( Category *category : categories )
        {
            posY = category->Update( posY ) + 10;
        }
    }

    void Window::Draw()
    {
        for( Category *category : categories )
        {
            category->Draw();
        }
    }
}
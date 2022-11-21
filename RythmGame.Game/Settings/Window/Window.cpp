#include "Window.h"

namespace RythmGame::Game::Settings
{

    Window::Window()
    {
        categories.push_back( new Category() );
    }

    Window::~Window()
    {
    }

    void Window::Draw()
    {
        for( Category *category : categories )
        {
            category->Draw();
        }
    }
}
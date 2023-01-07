#pragma once

namespace RythmGame::Game::Exit
{

    class Window
    {
        bool isExit;

    public:
        Window();
        ~Window();

        void Update();
        bool IsExit() { return isExit; }
    };

}
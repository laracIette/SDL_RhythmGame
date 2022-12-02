#pragma once

#include "ButtonTemplate.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class PlayButton : public ButtonTemplate
    {
        ButtonTemplate *buttons[4];

        bool isClicked, isStartGame;

    public:
    /**
        PlayButton inherits from ButtonTemplate
    */
        PlayButton() : ButtonTemplate(
            "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.png",
            BottomLeft
        )
        {
            buttons[PlayBack]    = new ButtonTemplate(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.Back.png",
                BottomRight
            );
            buttons[PlaySolo]    = new ButtonTemplate(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.Solo.png",
                BottomLeft
            );
            buttons[PlayMulti]   = new ButtonTemplate(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.Multiplayer.png",
                TopLeft
            );
            buttons[PlayOffline] = new ButtonTemplate(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.Offline.png",
                TopRight
            );

            isClicked = false;
            isStartGame = false;

        }

        bool StartGame()
        {
            return (isClicked && isStartGame);
        }

        bool IsClicked()
        {
            return isClicked;
        }

        void Update()
        {
            Hoover();
            UpdateZoom();

            if( !isClicked && IsLeftClicked() )
            {
                isClicked = true;
                return;
            }

            if( isClicked )
            {
                for( ButtonTemplate *button : buttons )
                {
                    button->Update();
                }

                if( buttons[PlaySolo]->IsLeftClicked() )
                {
                    isStartGame = true;
                }
            }

            if( !isClicked )
            {
                IsShown( true );
            }
            else
            {
                for( ButtonTemplate *button : buttons )
                {
                    button->IsShown( true );
                }
            }
        }
    };

}
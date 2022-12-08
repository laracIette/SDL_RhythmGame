#pragma once

#include "Button.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class PlayButton : public Button<ImageBottomLeft>
    {
        Button<ImageBottomRight> *backButton;
        Button<ImageBottomLeft>  *soloButton;
        Button<ImageTopLeft>     *multiplayerButton;
        Button<ImageTopRight>    *offlineButton;

        bool isClicked, isStartGame;

    public:
    /**
        PlayButton inherits from Button
    */
        PlayButton() :
            Button(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.png"
            )
        {
            backButton = new Button<ImageBottomRight>(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.Back.png"
            );
            soloButton = new Button<ImageBottomLeft>(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.Solo.png"
            );
            multiplayerButton = new Button<ImageTopLeft>(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.Multiplayer.png"
            );
            offlineButton = new Button<ImageTopRight>(
                "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.Offline.png"
            );

            isClicked   = false;
            isStartGame = false;

        }

        bool StartGame()
        {
            return (IsClicked() && isStartGame);
        }

        bool IsClicked()
        {
            return isClicked;
        }

        void Update()
        {
            Hoover();
            UpdateZoom();

            if( !isClicked && IsHooverLeftClicked() )
            {
                isClicked = true;
                return;
            }

            if( isClicked )
            {
                backButton->Update();
                soloButton->Update();
                multiplayerButton->Update();
                offlineButton->Update();

                if( soloButton->IsHooverLeftClicked() )
                {
                    isStartGame = true;
                }
            }

            if( !isClicked )
            {
                Show();
            }
            else
            {
                backButton->Show();
                soloButton->Show();
                multiplayerButton->Show();
                offlineButton->Show();
            }
        }
    };

}
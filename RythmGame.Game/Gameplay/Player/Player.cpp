#include "Player.h"

namespace RythmGame::Game::Gameplay
{

    Player::Player()
    {
        for( int i{ 0 }; i < nIMAGES; ++i )
        {
            images[i] = new Image(
                "assets/Skins/BaseSkin/Player/Player" + std::to_string( i ) + ".png",
                {0, 0, 60, 60},
                {(float)WIDTH/2, (float)HEIGHT/2, 60, 60}
            );
        }
    }
    Player::~Player()
    {
    }

    void Player::Input()
    {
        for( bool &b : isImageShown ) b = false;

        if( !inputManager.KeyLock( inputManager.flipKey ) && inputManager.Pressed( inputManager.flipKey ) )
        {
            inputManager.SetKeyLock( inputManager.flipKey, true );

            (isHorizontal) ? isHorizontal = false : isHorizontal = true;
        }


        (isHorizontal) ? isImageShown[HorizontalDefault] = true
                    : isImageShown[VerticalDefault] = true;



        if( inputManager.Left2Pressed() )
        {
            //isImageShown[UpLeft] = true;
            (isHorizontal) ? isImageShown[UpLeft] = true : isImageShown[UpRight] = true;
        }
        if( inputManager.Left1Pressed() )
        {
            //isImageShown[DownLeft] = true;
            (isHorizontal) ? isImageShown[DownLeft] = true : isImageShown[UpLeft] = true;
        }


        if( inputManager.Right1Pressed() )
        {
            //isImageShown[UpRight] = true;
            (isHorizontal) ? isImageShown[UpRight] = true : isImageShown[DownLeft] = true;
        }
        if( inputManager.Right2Pressed() )
        {
            //isImageShown[DownRight] = true;
            (isHorizontal) ? isImageShown[DownRight] = true : isImageShown[DownRight] = true;
        }

    }

    void Player::Draw()
    {
        for( int i{ 0 }; i < nIMAGES; ++i )
        {
            if( isImageShown[i] ) images[i]->Draw();
        }
    }

}
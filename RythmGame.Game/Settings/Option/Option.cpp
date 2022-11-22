#include "Option.h"

namespace RythmGame::Game::Settings
{

    Option::Option( const char *text )
    {
        this->text = new TextTTF( text, optionFont, 10, 0 );

        backgroundRect = new SDL_Rect();

        backgroundRect->x = resize( 10 );
        backgroundRect->y = 0;
        backgroundRect->w = this->text->W();
        backgroundRect->h = this->text->H();

        backgroundColor = White/2;
    }

    void Option::Update( int posY )
    {
        text->Update( posY );
        backgroundRect->y = text->Y();
    }

    void Option::Draw()
    {
        window->DrawRectangle( backgroundRect, backgroundColor );
        text->Draw();
    }

}

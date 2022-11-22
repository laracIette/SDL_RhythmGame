#include "Category.h"

namespace RythmGame::Game::Settings
{

    Category::Category( const char *title, std::vector<const char *> optionsVector )
    {
        this->title = new TextTTF( title, optionFont, 0, 0 );

        backgroundRect = new SDL_Rect();

        backgroundRect->x = 0;
        backgroundRect->y = 0;
        backgroundRect->w = resize( 1920/3 );
        backgroundRect->h = 0;

        backgroundColor = (Red + Blue)/2;

        for( const char *option : optionsVector )
        {
            options.push_back( new Option( option ) );
        }
    }

    Category::~Category()
    {
    }

    int Category::Update( int posY )
    {
        title->Update( posY );
        backgroundRect->y = title->Y();
        posY += FONT_SIZE_CATEGORY_TITLE + 6;

        for( Option *option : options )
        {
            option->Update( posY );
            posY += FONT_SIZE_OPTION + 6;
        }

        backgroundRect->h = resize( posY ) - backgroundRect->y;

        return posY;
    }

    void Category::Draw()
    {
        window->DrawRectangle( backgroundRect, backgroundColor );
        title->Draw();

        for( Option *option : options )
        {
            option->Draw();
        }
    }

}

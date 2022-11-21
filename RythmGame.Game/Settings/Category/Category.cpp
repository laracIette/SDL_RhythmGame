#include "Category.h"

namespace RythmGame::Game::Settings
{

    Category::Category( const char *title, std::vector<const char *> optionsVector )
    {
        this->title = new TextTTF( title, optionFont, 0, 0 );

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
        posY += 36;

        for( Option *option : options )
        {
            option->Update( posY );
            posY += 30;
        }

        return posY;
    }

    void Category::Draw()
    {
        title->Draw();

        for( Option *option : options )
        {
            option->Draw();
        }
    }

}

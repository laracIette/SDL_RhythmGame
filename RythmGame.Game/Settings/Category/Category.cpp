#include "Category.h"

namespace RythmGame::Game::Settings
{

    Category::Category()
    {
        options.push_back( new Option( "Yo !" ) );
    }

    Category::~Category()
    {
    }

    void Category::Draw()
    {
        for( Option *option : options )
        {
            option->Draw();
        }
    }

}

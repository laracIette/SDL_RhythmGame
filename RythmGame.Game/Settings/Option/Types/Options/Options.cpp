#include "Options.h"

namespace RythmGame::Game::Settings::Option
{

    void Options::Update( int posY )
    {
        UpdateText( posY );

        if( isSelected )
        {
            int tempIndex{ index };
            for( TextTTF *option : options )
            {
                option->Update( posY - FONT_SIZE_OPTION*tempIndex-- );
            }
        }
    }

    void Options::Draw()
    {
        if( isSelected )
        {
            for( TextTTF *option : options )
            {
                option->Draw();
            }
        }
        else
        {
            DrawText();
        }
    }

}
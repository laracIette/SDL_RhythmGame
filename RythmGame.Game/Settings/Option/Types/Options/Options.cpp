#include "Options.h"

namespace RythmGame::Game::Settings::Option
{

    std::pair<int, int> Options::Update( int posY )
    {
        UpdateText( posY );

        int up{ 0 };
        int down{ FONT_SIZE_OPTION*index };
        if( isSelected )
        {
            int tempIndex{ index };
            for( TextTTF *option : options )
            {
                up = -FONT_SIZE_OPTION*tempIndex--;
                option->Update( posY + up );
            }
            backgroundRect->y = options[0]->Y();

        }

        return {up, down};
    }

    void Options::Draw()
    {

        if( isSelected )
        {
            window->DrawRectangle( backgroundRect, backgroundColor );

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
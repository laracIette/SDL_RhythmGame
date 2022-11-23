#include "OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    OptionTemplate::OptionTemplate( std::string text )
    {
        this->text = new TextTTF( text, optionFont, 10, 0 );
    }

    OptionTemplate::~OptionTemplate()
    {
    }

    void OptionTemplate::UpdateText( int posY )
    {
        text->Update( posY );
    }

    void OptionTemplate::DrawText()
    {
        text->Draw();
    }

}

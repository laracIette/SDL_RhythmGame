#include "OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    OptionTemplate::OptionTemplate( std::string text, float value, int type )
    {
        this->text       = new TextTTF( text, optionFont, 10, 0 );
        this->value      = value;
        this->type       = type;
        this->name       = text;
        this->isSelected = false;
    }

    OptionTemplate::~OptionTemplate()
    {
    }

    void OptionTemplate::UpdateText( int posY )
    {
        text->Update( posY );

        if( text->IsHooverLeftClicked() )
        {
            isSelected = !isSelected;
        }
    }

    void OptionTemplate::DrawText()
    {
        text->Draw();
    }

    bool OptionTemplate::IsValueCanged()
    {
        if( oldValue != value )
        {
            oldValue = value;
            return 1;
        }
        return 0;
    }

}

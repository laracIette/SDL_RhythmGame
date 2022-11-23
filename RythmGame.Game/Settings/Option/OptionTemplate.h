#pragma once

#include <string>

#include "../../Events/InputManager.h"

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"
#include "../../../RythmGame.Graphics/Image/Image.h"

#include "../../../RythmGame.Framework/Window/Window.h"


using namespace RythmGame::Graphics;
using namespace RythmGame::Framework;
using namespace RythmGame::Game::Events;

namespace RythmGame::Game::Settings::Option
{
    enum Types {
        TypeValue = 0,
        TypeSlider,
        TypeCheck
    };

    class OptionTemplate
    {
        int         type;
        std::string name;
        float       oldValue;

    protected:
        TextTTF *text;
        float    value;

    public:
        OptionTemplate( std::string text, float value, int type );
        ~OptionTemplate();

        void         UpdateText( int posY );
        void         DrawText();

        virtual void Update( int posY ) {}
        virtual void Draw() {}

        int          GetType()  { return type; }
        std::string  GetName()  { return name; }
        float        GetValue() { return value; }

        bool         IsValueCanged();
    };

}

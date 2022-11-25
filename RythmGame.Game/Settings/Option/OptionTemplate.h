#pragma once

#include <string>
#include <vector>
#include <SDL.h>
#include <map>

#include "../../Events/InputManager.h"
#include "../../Utils/GameSettings.h"

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"
#include "../../../RythmGame.Graphics/Image/Image.h"
#include "../../../RythmGame.Graphics/ImageManager.h"

#include "../../../RythmGame.Framework/Window/Window.h"


using namespace RythmGame::Graphics;
using namespace RythmGame::Framework;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Game::Utils;

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
        bool     isSelected;

    public:
        OptionTemplate( std::string text, float value, int type );
        ~OptionTemplate();

        void         UpdateText( int posY );
        void         DrawText();

        virtual void Draw() {}

        int          GetType()  { return type; }
        std::string  GetName()  { return name; }
        float        GetValue() { return value; }

        bool         IsValueCanged();

        int X() { return text->X(); }
        int Y() { return text->Y(); }
        int W() { return text->W(); }
        int H() { return text->H(); }

        virtual std::pair<int, int> Update( int posY ) { return {0, 0}; }

    };

}

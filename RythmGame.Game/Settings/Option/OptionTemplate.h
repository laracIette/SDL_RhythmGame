#pragma once

#include <string>

#include "../../Utils/GameSettings.h"

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"

#include "../../../RythmGame.Framework/Window/Window.h"

#include "../../../RythmGame.Graphics/Image/Image.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Framework;

namespace RythmGame::Game::Settings::Option
{

    class OptionTemplate
    {
    protected:
        TextTTF *text;

    public:
        OptionTemplate( std::string text );
        ~OptionTemplate();

        void UpdateText( int posY );
        void DrawText();

        virtual void Update( int posY ) {}
        virtual void Draw() {}
    };

}

#ifndef INCLUDES_H
#define INCLUDES_H


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include <math.h>
#include <filesystem>
#include <vector>

#include "RythmGame.Framework/Window/Window.h"

#include "RythmGame.Game/Events/InputManager.h"
#include "RythmGame.Game/Events/KeyboardEvents.h"
#include "RythmGame.Game/Events/MouseEvents.h"

#include "RythmGame.Game/Gameplay/Accuracy/Accuracy.h"
#include "RythmGame.Game/Gameplay/Combo/Combo.h"
#include "RythmGame.Game/Gameplay/Map/Map.h"
#include "RythmGame.Game/Gameplay/Player/Player.h"
#include "RythmGame.Game/Gameplay/Score/Score.h"

#include "RythmGame.Game/Gameplay/Hit/Chainsaw.h"
#include "RythmGame.Game/Gameplay/Hit/Coin.h"
#include "RythmGame.Game/Gameplay/Hit/Double.h"
#include "RythmGame.Game/Gameplay/Hit/Ghost.h"
#include "RythmGame.Game/Gameplay/Hit/Hammer.h"
#include "RythmGame.Game/Gameplay/Hit/HitObject.h"
#include "RythmGame.Game/Gameplay/Hit/Hold.h"
#include "RythmGame.Game/Gameplay/Hit/Mash.h"
#include "RythmGame.Game/Gameplay/Hit/Note.h"

#include "RythmGame.Game/Utils/GameSettings.h"
#include "RythmGame.Game/Utils/Metrics.h"
#include "RythmGame.Game/Utils/Point.h"
#include "RythmGame.Game/Utils/Time.h"

#include "RythmGame.Game/Run/Run.h"

#include "RythmGame.Graphics/Animation/Animation.h"
#include "RythmGame.Graphics/Image/Image.h"
#include "RythmGame.Graphics/Text/Text.h"
#include "RythmGame.Graphics/TextureManager/TextureManager.h"

#include "RythmGame.Sound/HitSound/HitSound.h"
#include "RythmGame.Sound/HitSoundManager/HitSoundManager.h"
#include "RythmGame.Sound/Music/Music.h"


#endif // INCLUDES_H
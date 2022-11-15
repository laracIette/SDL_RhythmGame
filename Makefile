SDL:
	g++ \
	-I/home/nico/SDL-release-2.24.0/include \
	-I/home/nico/SDL2_image-2.6.2 \
	-I/home/nico/SDL2_mixer-2.6.2/include \
	-o build/prog \
	src/main.cpp \
	RythmGame.Framework/Window/Window.cpp \
	RythmGame.Game/Run/Run.cpp \
	RythmGame.Game/Gameplay/Player/Player.cpp \
	RythmGame.Game/Gameplay/Map/Map.cpp \
	RythmGame.Game/Gameplay/Score/Score.cpp \
	RythmGame.Graphics/TextureManager/TextureManager.cpp \
	RythmGame.Graphics/Image/Image.cpp \
	RythmGame.Graphics/Animation/Animation.cpp \
	RythmGame.Graphics/Text/Text.cpp \
	RythmGame.Sound/Music/Music.cpp \
	RythmGame.Sound/HitSound/HitSound.cpp \
	RythmGame.Sound/HitSoundManager/HitSoundManager.cpp \
	-lSDL2main \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_mixer

.PHONY: test clean

test: SDL
	build/prog

clean:
	rm -f SDL
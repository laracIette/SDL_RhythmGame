SDL:
	g++ \
	-I/home/nico/SDL-release-2.24.0/include \
	-I/home/nico/SDL2_image-2.6.2 \
	-I/home/nico/SDL2_mixer-2.6.2/include \
	-I/home/nico/SDL2_ttf-2.20.1 \
	-o build/prog \
	src/main.cpp \
	RythmGame.Framework/Window/Window.cpp \
	RythmGame.Framework/File/File.cpp \
	RythmGame.Game/Run/Run.cpp \
	RythmGame.Game/Song/Song.cpp \
	RythmGame.Game/Gameplay/Player/Player.cpp \
	RythmGame.Game/Gameplay/Map/Map.cpp \
	RythmGame.Game/Gameplay/Score/Score.cpp \
	RythmGame.Game/Gameplay/Combo/Combo.cpp \
	RythmGame.Game/Gameplay/Accuracy/Accuracy.cpp \
	RythmGame.Game/Settings/Category/Category.cpp \
	RythmGame.Game/Settings/Option/Option.cpp \
	RythmGame.Game/Settings/Window/Window.cpp \
	RythmGame.Game/Menu/StartScreen/Screen/Screen.cpp \
	RythmGame.Game/Menu/MapSelection/Screen/Screen.cpp \
	RythmGame.Game/Menu/MapSelection/SongTile/SongTile.cpp \
	RythmGame.Graphics/TextureManager/TextureManager.cpp \
	RythmGame.Graphics/Image/Image.cpp \
	RythmGame.Graphics/Animation/Animation.cpp \
	RythmGame.Graphics/Text/Text.cpp \
	RythmGame.Graphics/TextTTF/TextTTF.cpp \
	RythmGame.Sound/Music/Music.cpp \
	RythmGame.Sound/HitSound/HitSound.cpp \
	RythmGame.Sound/HitSoundManager/HitSoundManager.cpp \
	-lSDL2main \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_mixer \
	-lSDL2_ttf

.PHONY: test clean

test: SDL
	build/prog

clean:
	rm -f SDL
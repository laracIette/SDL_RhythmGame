SDL:
	g++ \
	-I/home/nico/SDL-release-2.24.0/include \
	-I/home/nico/SDL2_image-2.6.2 \
	-I/home/nico/SDL2_mixer-2.6.2/include \
	-o build/prog \
	src/main.cpp \
	lib/Window/Window.cpp \
	lib/Game/Game.cpp \
	lib/TextureManager/TextureManager.cpp \
	lib/Player/Player.cpp \
	lib/Image/Image.cpp \
	lib/Map/Map.cpp \
	lib/SoundManager/SoundManager.cpp \
	-lSDL2main \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_mixer

.PHONY: test clean

test: SDL
	build/prog

clean:
	rm -f SDL
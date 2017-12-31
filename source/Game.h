#pragma once
#include "SDL.h"
#include "SDL_image.h"
#undef main
#include <iostream>
class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }
	static SDL_Event event;
	static SDL_Renderer* renderer;

private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
};


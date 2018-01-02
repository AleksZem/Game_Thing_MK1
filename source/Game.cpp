#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "EntityComponent\Components.h"
#include "Collision.h"

Map* map1;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;
std::vector<CollisionComponent*> Game::colliders;
auto& newPlayer(manager.addEntity());
auto& boundary(manager.addEntity());
auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

Game::Game(){

}


Game::~Game(){

}

void Game::init(const char * title, int xPos, int yPos, int width, int height, bool fullScreen){

	int flags = 0;
	if (fullScreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized" << std::endl;
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	map1 = new Map();
	tile0.addComponents<TileComponent>(200, 200, 32, 32, 0);
	tile1.addComponents<TileComponent>(250, 250, 32, 32, 2);
	tile1.addComponents<CollisionComponent>("dirt");
	tile2.addComponents<TileComponent>(150,150,32,32,1);
	tile2.addComponents<CollisionComponent>("grass");
	newPlayer.addComponents<TransformComponent>(2);
	newPlayer.addComponents<SpriteComponent>("assets/Player.png");
	newPlayer.addComponents<KeyboardController>();
	newPlayer.addComponents<CollisionComponent>("Me");
	boundary.addComponents<TransformComponent>(400.0f, 400.0f, 300, 10, 1);
	boundary.addComponents<SpriteComponent>("assets/dirt.png");
	boundary.addComponents<CollisionComponent>("Boundary");
}

void Game::handleEvents() {
	
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}


void Game::update(){
	count++;
	manager.refresh();
	manager.update();

	for (auto collider : colliders) {
		Collision::AABBCollision(newPlayer.getComponent<CollisionComponent>(), *collider);
	}
	//std::cout << "Tick: " << count << ", " << newPlayer.getComponent<TransformComponent>().position;
}

void Game::render(){
	SDL_RenderClear(renderer);
	//map1->drawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}


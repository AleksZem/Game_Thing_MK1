#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char * textureSheet, int x, int y){
	objectTexture = TextureManager::loadTexture(textureSheet);
	xPosition = x;
	yPosition = y;
}

GameObject::~GameObject(){}

void GameObject::update(){
	xPosition++;
	yPosition++;
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xPosition;
	destRect.y = yPosition;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
}

void GameObject::render(){
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}

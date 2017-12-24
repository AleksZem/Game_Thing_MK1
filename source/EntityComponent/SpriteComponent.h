#pragma once
#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component {
private:
	TransformComponent * transform;
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
public:
	SpriteComponent() = default;
	SpriteComponent(const char* filePath) {
		setTexture(filePath);
	}

	void setTexture(const char* filePath) {
		texture = TextureManager::loadTexture(filePath);
	}

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
	}
	void update() override {
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
	}
	void draw() override {
		TextureManager::draw(texture, srcRect, destRect);
	}
};
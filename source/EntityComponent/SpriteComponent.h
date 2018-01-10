#pragma once
#include "Components.h"
#include "../TextureManager.h"
#include "SDL.h"

class SpriteComponent : public Component {
private:
	TransformComponent * transform;
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
	bool animated = false;
	int frames = 0;
	int ms_delay = 100;
public:
	SpriteComponent() = default;
	SpriteComponent(const char* filePath) {
		setTexture(filePath);
	}
	SpriteComponent(const char* filePath, int num_frames, int delay) {
		if (num_frames > 1) {
			animated = true;
			frames = num_frames;
			ms_delay = delay;
		}
		setTexture(filePath);
	}
	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}

	void setTexture(const char* filePath) {
		texture = TextureManager::loadTexture(filePath);
	}

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}
	void update() override {
		if (animated) {
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / ms_delay) % frames);
		}

		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}
	void draw() override {
		TextureManager::draw(texture, srcRect, destRect);
	}
};
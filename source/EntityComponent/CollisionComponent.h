#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"

class CollisionComponent : public Component {
	SDL_Rect collider;
	std::string colliderTag;

	TransformComponent* transform;
	void init() override {
		if (!entity->hasComponent<TransformComponent>()) {
			entity->addComponents<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
	}
	

};
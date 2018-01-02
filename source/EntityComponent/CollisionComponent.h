#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"

class CollisionComponent : public Component {
public:
	SDL_Rect collider;
	std::string colliderTag;
	TransformComponent* transform;

	CollisionComponent(std::string Tag) { colliderTag = Tag; }

	void init() override {
		if (!entity->hasComponent<TransformComponent>()) {
			entity->addComponents<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
	

};
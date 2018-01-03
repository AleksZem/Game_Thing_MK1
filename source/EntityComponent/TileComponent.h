#pragma once
#include "EntityComponentSystem.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL.h"

class TileComponent : public Component {
public:
	TransformComponent * transform;
	SpriteComponent * sprite;
	SDL_Rect tileRec;
	int tileID;
	const char* filePath;
	TileComponent() = default;
	TileComponent(int x, int y, int width, int height, int ID) {
		tileRec.x = x;
		tileRec.y = y;
		tileRec.h = height;
		tileRec.w = width;
		tileID = ID;
		switch (tileID)
		{
		case 0:
			filePath = "assets/dirt.png";
			break;
		case 1:
			filePath = "assets/grass.png";
			break;
		case 2: 
			filePath = "assets/water.png";
			break;
		default:
			break;
		}
	}

	void init() override {
		entity->addComponents<TransformComponent>((float)tileRec.x, (float)tileRec.y, tileRec.w, tileRec.h, 1);
		transform = &entity->getComponent<TransformComponent>();
		entity->addComponents<SpriteComponent>(filePath);
		sprite = &entity->getComponent<SpriteComponent>();
	}
};
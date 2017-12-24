#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
private:
	
public:
	Vector2D position;

	TransformComponent() { position.x = position.y = 0.0f; }

	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	//void init() override {
	//	xPosition = 0;
	//	yPosition = 0;
	//}

	void update() override {

	}
};
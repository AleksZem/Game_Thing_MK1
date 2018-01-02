#pragma once
//#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
private:
	
public:
	Vector2D position;
	Vector2D velocity;
	int speed = 4;
	int height = 32;
	int width = 32;
	int scale = 1;

	TransformComponent() { position.zeroOut(); }

	TransformComponent(int scale) { 
		position.zeroOut(); 
		this->scale = scale;
	}

	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int height, int width, int scale) {
		position.x = x;
		position.y = y;
		this->height = height;
		this->width = width;
		this->scale = scale;

	}


	void init() override {	velocity.zeroOut(); }

	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};
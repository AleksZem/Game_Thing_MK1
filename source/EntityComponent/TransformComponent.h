#pragma once
#include "Components.h"

class TransformComponent : public Component {
private:
	int xPosition;
	int yPosition;
public:
	TransformComponent() { setPos(0, 0); }

	TransformComponent(int x, int y) {
		setPos(x, y);
	}

	int x() { return xPosition; }
	int y() { return yPosition; }

	//void init() override {
	//	xPosition = 0;
	//	yPosition = 0;
	//}

	void update() override {
		xPosition++;
		yPosition++;
	}

	void setPos(int x, int y) {
		xPosition = x;
		yPosition = y;
	}

	void setX(int x) { xPosition = x; }
	void setY(int y) { yPosition = y; }
};
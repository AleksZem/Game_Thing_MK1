#pragma once
#include "SDL.h"

class CollisionComponent;

class Collision {
public:
	static bool AABBCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);
	static bool AABBCollision(const CollisionComponent& colliderA, const CollisionComponent& colliderB);
private:
};
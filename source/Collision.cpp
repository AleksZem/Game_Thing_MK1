#include "Collision.h"
#include "EntityComponent/CollisionComponent.h"

bool Collision::AABBCollision(const SDL_Rect & rectA, const SDL_Rect & rectB)
{
	if (rectA.x + rectA.w >= rectB.x
		&& rectB.x + rectB.w >= rectA.x
		&& rectA.y + rectA.h >= rectB.y
		&& rectB.y + rectB.h >= rectA.y) {
		return true;
	}
	else {
		return false;
	}
}

bool Collision::AABBCollision(const CollisionComponent & colliderA, const CollisionComponent & colliderB){
	if (AABBCollision(colliderA.collider, colliderB.collider)) {
		std::cout << colliderA.colliderTag << " hit detected: " << colliderB.colliderTag << std::endl;
		return true;
	}
	return false;
}

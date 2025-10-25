#pragma once
#include <SFML/Graphics.hpp>
#include "WorldMap.h"

#define PI  3.14159

using namespace sf;

class Player
{
private:
	bool CollisionDetection(Vector2f direction);
	double movementSpeed = 1.0;
	float rotationAmount = 0.1f;

public:
	CircleShape shape;
	Player()
	{
		shape.setRadius(10.f);
		shape.setPointCount(3);
		shape.setOrigin(Vector2f(shape.getRadius(), shape.getRadius()));
		shape.setPosition(Vector2f(resX / 2, resY / 2));
	}
	void move(CircleShape &playerShape);
};


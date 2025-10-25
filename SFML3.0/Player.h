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
    struct Directions
	{
		Vector2f up{ 0,-1.f };
		Vector2f down{ 0, 1.f };
		Vector2f left{ -1.f, 0 };
		Vector2f right{ 1.f,0 };
	};

public:
	double angle = 0.0;
	Directions directions;
	CircleShape shape;
	Player()
	{
		shape.setRadius(10.f);
		shape.setPointCount(3);
		shape.setOrigin(Vector2f(shape.getRadius(), shape.getRadius()));
		shape.setPosition(Vector2f(resX / 2, resY / 2));
	}
	Vector2f direction_with_rotation(Vector2f direction);
	void move(CircleShape &playerShape);
};


#pragma once
#include <SFML/Graphics.hpp>
#include "WorldMap.h"
#include "DebugMode.h"

#define PI  3.14159
#define FOV 66.0


using namespace sf;

static const double MovementSpeed{ 2.0 };

class Player
{
	
private:
	bool CollisionDetection(Vector2f direction);
    struct Directions
	{
		Vector2f up{ 0,-1.f * MovementSpeed};
		Vector2f down{ 0, 1.f * MovementSpeed };
		Vector2f left{ -1.f * MovementSpeed, 0 };
		Vector2f right{ 1.f * MovementSpeed,0 };
	};


public:
	double rotationAngle{ 0.0 };
	Directions directions;
	CircleShape shape;
	RectangleShape lineOfSight;
	Vector2f lookingDirection;
	Player()
	{
		if (DEBUG == 0)
		{
			lineOfSight.setSize(Vector2f(2.f, 10.f));
			lineOfSight.setOrigin(Vector2f(-1, -1));
			shape.setRadius(5.f);
			shape.setPointCount(3);
			shape.setFillColor(Color::Transparent);
			shape.setOrigin(Vector2f(shape.getRadius(), shape.getRadius()));
			shape.setPosition(Vector2f(resX / 2, resY / 2));

		}
		else
		{
			lineOfSight.setSize(Vector2f(2.f, 10.f));
			lineOfSight.setOrigin(Vector2f(-1, -1));
			shape.setRadius(5.f);
			shape.setPointCount(3);
			shape.setFillColor(Color::Blue);
			shape.setOrigin(Vector2f(shape.getRadius(), shape.getRadius()));
			shape.setPosition(Vector2f(resX / 2, resY / 2));
		}
	}
	Vector2f direction_with_rotation(Vector2f direction);
	void move(CircleShape &playerShape, double deltaTime);
};


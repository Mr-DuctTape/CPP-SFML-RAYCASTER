#pragma once
#include "Player.h"

class Ray
{
private:
	Vector2f playerLocation;
	double angle = 0.0;
public:
	void DrawRay(RenderWindow  &window);
	Ray(Player &player, double radians) 
	{
		angle = radians;
		playerLocation = player.shape.getPosition();
	}
};


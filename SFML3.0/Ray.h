#pragma once
#include "Player.h"

class Ray{
private:
	Vector2f playerLocation;
	double angle{};
	RectangleShape line();
public:
	void DrawRay(RenderWindow  &window);
	Ray(Player &player, double radians) 
	{
		angle = radians;
		playerLocation = player.shape.getPosition();
	}
};


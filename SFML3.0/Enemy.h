#pragma once
#include "Player.h"
#include "WorldMap.h"

class Enemy
{
private:
	Vector2f position{};
	CircleShape enemyShape;
public:
	Enemy()
	{
		enemyShape.setRadius(20.f);
		enemyShape.setOrigin(Vector2f(enemyShape.getRadius(), enemyShape.getRadius()));
		enemyShape.setPosition(Vector2f(resX / 2 + 5, resY / 2 + 5));
	}
	void drawEnemy(RenderWindow& renderWindow, Player& player);
};

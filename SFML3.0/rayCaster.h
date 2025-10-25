#pragma once
#include "Player.h"

class rayCaster
{
private:
	double posX, posY;
	double dirX{ -1 }, dirY{0};
	double planeX{ 0 }, planeY{0.66};
public:
	std::vector<RectangleShape> walls;
	rayCaster(Player &player)
	{
		posX = player.shape.getPosition().x / ROWS;
		posY = player.shape.getPosition().y / COLUMNS;
	}
	void castRays(Player &player, World::WorldMap& worldMap);
	void DrawWalls(RenderWindow &window);
};


#pragma once
#include "Player.h"

class rayCaster
{
private:
	double FOV = 66.0;

public:
	std::vector<RectangleShape> walls;
	
	void castRays(Player &player, World::WorldMap& worldMap);
	void DrawWalls(RenderWindow &window);
};


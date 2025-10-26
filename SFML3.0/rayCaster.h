#pragma once
#include "Player.h"

enum RayQuality
{
	Amazing, // full resolution (ResX)
	Good, // half resolution (ResX / 2)
	Fast, // third resolution (ResX / 3)
	VeryFast // Quarter resolution (ResX / 4)
};

class rayCaster
{
private:
	double FOV = 66.0;

public:
	std::vector<RectangleShape> walls;
	
	void castRays(Player &player, World::WorldMap& worldMap);
	void DrawWalls(RenderWindow &window);
};


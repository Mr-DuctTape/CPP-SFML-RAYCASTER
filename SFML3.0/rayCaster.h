#pragma once
#include "Player.h"

enum RayQuality
{
	Amazing = 1, // full resolution (ResX)
	Good = 2, // half resolution (ResX / 2)
	Fast = 4, // third resolution (ResX / 4)
	VeryFast = 8 // Quarter resolution (ResX / 8)
};

class rayCaster
{
private:
	double FOV = 66.0;

public:
	std::vector<RectangleShape> walls;
	
	void castRays(Player &player, World::WorldMap& worldMap, int qualityIndex);
	void DrawWalls(RenderWindow &window);
};


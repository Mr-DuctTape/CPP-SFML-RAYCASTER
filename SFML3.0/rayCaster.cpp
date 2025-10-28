#include "rayCaster.h"
#include "WorldMap.h"


std::vector<RectangleShape> wallObjects;

void rayCaster::DrawWalls(RenderWindow& window)
{
	for (auto const &wall : wallObjects)
	{
		window.draw(wall);
	}
}

int getRayCount(int qualityIndex, int resX)
{
	return resX / qualityIndex;
}

void rayCaster::castRays(Player& player, World::WorldMap& worldMap, int qualityIndex)
{
	wallObjects.clear();

	double rayStartY = player.shape.getPosition().y / worldMap.cellSizeY;
	double rayStartX = player.shape.getPosition().x / worldMap.cellSizeX;

	Vector2f Dir = player.lookingDirection.normalized();
	Vector2f rightDir(-Dir.y, Dir.x);


	int raysToCast = getRayCount(qualityIndex, resX);

	double FOVradians = FOV * (PI / 180.0);
	double rayAngleStep = FOVradians / (double)raysToCast;

	for (int ray = 0; ray < raysToCast; ray++)
	{
		double rayAngle = -FOVradians / 2 + ray * rayAngleStep;

		Vector2f rayDir(Dir.x * cos(rayAngle) - Dir.y * sin(rayAngle), Dir.x * sin(rayAngle) + Dir.y * cos(rayAngle));

		double unitStepSizeX = (rayDir.x == 0) ? 1e30 : std::abs(1 / rayDir.x);
		double unitStepSizeY = (rayDir.y == 0) ? 1e30 : std::abs(1 / rayDir.y);

		int mapX = (int)rayStartX;
		int mapY = (int)rayStartY;

		double rayLengthX{};
		double rayLengthY{};

		double stepY{};
		double stepX{};

		if (rayDir.x < 0)
		{
			stepX = -1;

			rayLengthX = ((rayStartX - (float)mapX) * unitStepSizeX);
		}
		else
		{
			stepX = 1;
			rayLengthX = ((float(mapX + 1) - rayStartX) * unitStepSizeX);
		}

		if (rayDir.y < 0)
		{
			stepY = -1;
			rayLengthY = ((rayStartY - (float)mapY) * unitStepSizeY);
		}
		else
		{
			stepY = 1;
			rayLengthY = ((float(mapY + 1) - rayStartY) * unitStepSizeY);
		}

		bool bTileFound = false;
		float maxDistance = 100.0f;
		float currentDistance = 0.0f;
		bool hitVertical = false;

		while (!bTileFound && currentDistance < maxDistance)
		{
			//Walking ray
			if (rayLengthX < rayLengthY)
			{
				mapX += stepX;
				currentDistance = rayLengthX;
				rayLengthX += unitStepSizeX;
				hitVertical = true;
			}
			else
			{
				mapY += stepY;
				currentDistance = rayLengthY;
				rayLengthY += unitStepSizeY;
				hitVertical = false;
			}


			if (mapX >= 0 && mapX < World::MapLoader::X && mapY >= 0 && mapY < World::MapLoader::Y) //Bounds check
			{
				if (World::mapSize[mapY][mapX] == 1) //Found wall
				{
					bTileFound = true;
				}
			}
		}

		Vector2f intersection{};

		if (bTileFound)
		{
			intersection.x = (rayStartX + rayDir.x * currentDistance);
			intersection.y = (rayStartY + rayDir.y * currentDistance);

			float maxHeight = resY;
			float wallHeight = maxHeight / (currentDistance * cos(rayAngle));

			RectangleShape wall(Vector2f((float)qualityIndex, wallHeight));
			wall.setPosition(Vector2f(ray * (float)qualityIndex, resY / 2 - wallHeight / 2));

			if (hitVertical)
			{
				wall.setFillColor(Color(139, 0, 0));
			}
			else
			{
				wall.setFillColor(Color(255, 0, 0));
			}

			wallObjects.push_back(wall);
		}
	}
}

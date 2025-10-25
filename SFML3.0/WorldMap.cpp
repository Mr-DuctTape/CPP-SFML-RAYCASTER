#include "WorldMap.h"

std::vector<sf::RectangleShape> World::mapObjects;

void World::WorldMap::draw(sf::RenderWindow& window) 
{
	if (World::mapObjects.empty()) 
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			for (int x = 0; x < ROWS; x++)
			{
				if (mapSize[y][x] == 1)
				{
					//Cell is not empty
					sf::RectangleShape cell;
					cell.setSize(sf::Vector2f(cellSizeX, cellSizeY));
					cell.setPosition(sf::Vector2f(x * cellSizeX, y * cellSizeY));
					cell.setOutlineColor(sf::Color::White);
					cell.setOutlineThickness(1.f);
					World::mapObjects.push_back(cell);
				}
				else if (mapSize[y][x] == 0) 
				{
					sf::RectangleShape cell;
					cell.setSize(sf::Vector2f(cellSizeX, cellSizeY));
					cell.setFillColor(sf::Color::Black);
					cell.setOutlineColor(sf::Color::White);
					cell.setOutlineThickness(1.f);
					cell.setPosition(sf::Vector2f(x * cellSizeX, y * cellSizeY));
					Outlines.push_back(cell);
				}
			}
		}
	}
	else 
	{
		
		for (const auto cell : Outlines)
		{
			window.draw(cell);
		}

		for (const auto cell : World::mapObjects)
		{
			window.draw(cell);
		}
	}
}
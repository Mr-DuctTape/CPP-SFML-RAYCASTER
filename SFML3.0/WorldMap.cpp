#include "WorldMap.h"



namespace World
{
	std::vector<sf::RectangleShape> mapObjects;
	std::vector<std::vector<int>>mapSize;

	int MapLoader::X = 0;  // definition
	int MapLoader::Y = 0;  // definition


	void MapLoader::LoadMap(int mapLevel)
	{
		std::string mapPath = "C:\\Users\\Ebisu\\source\\repos\\Raycaster\\SFML3.0\\Map1.txt"; //Figure out a way to make this work without direct path
		std::ifstream mapFile(mapPath);

		if (!mapFile.is_open())
		{
			std::cerr << "Failed to open map file: " << mapPath << "\n";
			return;
		}


		while (std::getline(mapFile, this->mapAssets))
		{
			this->X = 0;
			World::mapSize.push_back({});
			for (char character : this->mapAssets)
			{
				if (character == '#')
				{
					// Found wall so add it too the vector array
					World::mapSize[this->Y].push_back({ 1 });
					this->X++;
				}
				else
				{
					World::mapSize[this->Y].push_back({ 0 });
					this->X++;
				}
			}
			this->Y++;
		}
	}

	void WorldMap::setCellSize()
	{
		if (MapLoader::X > 0 && MapLoader::Y > 0)
		{
			WorldMap::cellSizeX = (double)resX / MapLoader::X;
			WorldMap::cellSizeY = (double)resY / MapLoader::Y;
		}
		else
		{
			std::cout << "Invalid map dimensions!" << "\n";
		}
	}

	int widthX = MapLoader::X;
	int heightY = MapLoader::Y;

	void WorldMap::draw(sf::RenderWindow& window)
	{
		int widthX = MapLoader::X;
		int heightY = MapLoader::Y;


		if (World::mapObjects.empty())
		{
			for (int y = 0; y < heightY; y++)
			{
				for (int x = 0; x < widthX; x++)
				{
					if (DEBUG == 0)
					{
						if (mapSize[y][x] == 1)
						{
							//Cell is not empty
							sf::RectangleShape cell;
							cell.setSize(sf::Vector2f(cellSizeX, cellSizeY));
							cell.setPosition(sf::Vector2f(x * cellSizeX, y * cellSizeY));
							cell.setFillColor(sf::Color::Transparent);
							World::mapObjects.push_back(cell);
						}
						else if (mapSize[y][x] == 0)
						{
							sf::RectangleShape cell;
							cell.setSize(sf::Vector2f(cellSizeX, cellSizeY));
							cell.setFillColor(sf::Color::Transparent);
							cell.setPosition(sf::Vector2f(x * cellSizeX, y * cellSizeY));
							Outlines.push_back(cell);
						}
					}
					else if (DEBUG == 1)
					{
						if (mapSize[y][x] == 1)
						{
							//Cell is not empty
							sf::RectangleShape cell;
							cell.setSize(sf::Vector2f(cellSizeX, cellSizeY));
							cell.setPosition(sf::Vector2f(x * cellSizeX, y * cellSizeY));
							cell.setFillColor(sf::Color::White);
							World::mapObjects.push_back(cell);
						}
						else if (mapSize[y][x] == 0)
						{
							sf::RectangleShape cell;
							cell.setSize(sf::Vector2f(cellSizeX, cellSizeY));
							cell.setFillColor(sf::Color::Transparent);
							cell.setPosition(sf::Vector2f(x * cellSizeX, y * cellSizeY));
							Outlines.push_back(cell);
						}
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
}
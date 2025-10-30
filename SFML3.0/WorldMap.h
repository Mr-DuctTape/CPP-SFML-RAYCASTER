#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "DebugMode.h"
#include <fstream>


const int resX = 1280;
const int resY = 720;

namespace World
{

    class MapLoader
    {
    private:
        std::string mapAssets{};
    public:
        int mapLevel = 0;
        static int X, Y;

        void LoadMap(int mapLevel);
    };

    extern std::vector<sf::RectangleShape> mapObjects;

    extern std::vector<std::vector<int>>mapSize;


    class WorldMap
    {
    public:
        double cellSizeX{ 0.0 };
        double cellSizeY{ 0.0 };

        std::vector<sf::RectangleShape> mapObjects;
        std::vector<sf::RectangleShape> Outlines;

        void setCellSize();
        void draw(sf::RenderWindow& window);
    };
}



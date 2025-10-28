#include <SFML/Graphics.hpp>
#include <iostream>
#include "WorldMap.h"
#include "Player.h"
#include "DebugMode.h"
#include "rayCaster.h"


using namespace sf;
using namespace World;

int main()
{
    // Create the main window
    RenderWindow window(VideoMode({resX,resY,}), "Raycaster", sf::Style::Default);

    MapLoader mapLoader;

    mapLoader.LoadMap(1);


    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    WorldMap worldMap;

    worldMap.setCellSize();

    Player player;

    rayCaster raycaster;
    int qualityNumber{};
    std::cout << "Type a number for the resolution of the screen: ";
    std::cin >> qualityNumber;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        player.move(player.shape, 2.0);

        window.clear();

        if (DEBUG == 0)
        {
            worldMap.draw(window);

            window.draw(player.shape);

            raycaster.castRays(player, worldMap, qualityNumber);

            raycaster.DrawWalls(window);
        }
        else
        {
            window.draw(player.shape);
            window.draw(player.lineOfSight);
            worldMap.draw(window);
        }
        window.display();
    }

    return 0;
}
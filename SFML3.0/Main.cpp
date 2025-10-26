#include <SFML/Graphics.hpp>
#include <iostream>
#include "WorldMap.h"
#include "Player.h"
#include "rayCaster.h"

#define DEBUG 1

using namespace sf;
using namespace World;

int main()
{
    // Create the main window
    RenderWindow window(VideoMode({resX,resY,}), "Raycaster");

    WorldMap worldMap;

    window.setFramerateLimit(60);

    Player player;

    rayCaster raycaster;


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

        player.move(player.shape);

        window.clear();

        if (DEBUG == 0)
        {
            worldMap.draw(window);

            window.draw(player.shape);
       
            window.draw(player.lineOfSight);
        }
        else
        {

            raycaster.castRays(player, worldMap);
            raycaster.DrawWalls(window);
        }

        window.display();
    }

    return 0;
}
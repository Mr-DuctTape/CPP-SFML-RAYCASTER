#include <SFML/Graphics.hpp>
#include <iostream>
#include "WorldMap.h"
#include "Player.h"

using namespace sf;

int main()
{
    // Create the main window
    RenderWindow window(VideoMode({resX,resY,}), "SFML window");

    

    WorldMap worldMap;

    window.setFramerateLimit(60);

    Player player;

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

        worldMap.draw(window);

        window.draw(player.shape);

        window.display();
    }

    return 0;
}
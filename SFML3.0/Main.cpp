#include <SFML/Graphics.hpp>
#include <iostream>
#include "WorldMap.h"
#include "Player.h"
#include "DebugMode.h"
#include "rayCaster.h"
#include "Enemy.h"

using namespace sf;
using namespace World;




int main()
{
    // Create the main window and settings
    RenderWindow window(VideoMode({resX,resY,}), "Raycaster", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(300);


    //Map iniz
    MapLoader mapLoader;
    mapLoader.LoadMap(1);
    WorldMap worldMap;
    worldMap.setCellSize();


    //temporary test stuff
    CircleShape crossHair(2.f);
    crossHair.setPosition(Vector2f(resX / 2.0, resY / 2.0)); //This is temporary :D


  
    //Enteties
    Player player;
    Enemy enemy;


    //Raycaster
    rayCaster raycaster;
    int qualityNumber{1};
 /*   std::cout << "Type a number for the resolution of the screen: ";
    std::cin >> qualityNumber;*/

    
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


        //Updates
        player.move(player.shape, 2.0);


        //Rendering part
        window.clear();

        if (DEBUG == 0)
        {
            worldMap.draw(window);

            window.draw(player.shape);

            raycaster.castViewRays(player, worldMap, qualityNumber);

            raycaster.DrawWalls(window);

            window.draw(crossHair);

            enemy.drawEnemy(window, player);
        }
        else
        {
            window.draw(player.shape);
            window.draw(player.lineOfSight);
            worldMap.draw(window);
            enemy.drawEnemy(window, player);
        }
        window.display();
    }

    return 0;
}
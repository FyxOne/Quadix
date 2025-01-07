#include "engine.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream> // Äëÿ std::cerr

void generateWorld(sf::RenderWindow& window) {
    std::cout << "Generating world..." << std::endl;
    const int tileSize = 16;
    const int worldWidth = 50; // Width of the world in tiles
    const int worldHeight = 30; // Height of the world in tiles

    // Load textures
    sf::Texture grassTexture, dirtTexture, stoneTexture, logTexture, leavesTexture;
    sf::Texture ironTexture, aluminiumTexture, copperTexture, goldTexture, emeraldTexture;

    if (!grassTexture.loadFromFile("resources/grass.png") ||
        !dirtTexture.loadFromFile("resources/dirt.png") ||
        !stoneTexture.loadFromFile("resources/stone.png") ||
        !logTexture.loadFromFile("resources/log.png") ||
        !leavesTexture.loadFromFile("resources/leaves.png") ||
        !ironTexture.loadFromFile("resources/iron_ore.png") ||
        !aluminiumTexture.loadFromFile("resources/aluminium_ore.png") ||
        !copperTexture.loadFromFile("resources/cooper_ore.png") ||
        !goldTexture.loadFromFile("resources/gold_ore.png") ||
        !emeraldTexture.loadFromFile("resources/emerald_ore.png")) {
        std::cerr << "Error: Could not load one or more textures." << std::endl;
        return;
    }

    // Create a 2D array for the world
    std::vector<std::vector<sf::Sprite>> world(worldHeight, std::vector<sf::Sprite>(worldWidth));

    // Seed for procedural generation
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int y = 0; y < worldHeight; ++y) {
        for (int x = 0; x < worldWidth; ++x) {
            sf::Sprite tile;

            if (y == worldHeight - 1) {
                tile.setTexture(grassTexture);
            }
            else if (y >= worldHeight - 4) {
                tile.setTexture(dirtTexture);
            }
            else if (y >= worldHeight - 6) {
                tile.setTexture(stoneTexture);

                // Randomly add ores
                int oreChance = std::rand() % 100;
                if (oreChance < 5) {
                    tile.setTexture(ironTexture);
                }
                else if (oreChance < 10) {
                    tile.setTexture(aluminiumTexture);
                }
                else if (oreChance < 15) {
                    tile.setTexture(copperTexture);
                }
                else if (oreChance < 20) {
                    tile.setTexture(goldTexture);
                }
                else if (oreChance < 25) {
                    tile.setTexture(emeraldTexture);
                }
            }

            tile.setPosition(x * tileSize, y * tileSize);
            world[y][x] = tile;
        }
    }

    // Render the world
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        for (int y = 0; y < worldHeight; ++y) {
            for (int x = 0; x < worldWidth; ++x) {
                window.draw(world[y][x]);
            }
        }
        window.display();
    }
}

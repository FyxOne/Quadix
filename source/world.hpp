#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>

// Super cool config
#define WORLD_SIZE_W 75
#define WORLD_SIZE_H 32
#define TILE_SIZE 32

#define TEXTURE_AIR 0
#define TEXTURE_GRASS 1
#define TEXTURE_DIRT 2
#define TEXTURE_STONE 3

// Tiles textures
struct tile_textures
{
    static sf::Texture dirt;
    static sf::Texture grass;
    static sf::Texture stone;

    static void initialize();
};

// World class! Sounds good!
class World : public sf::Drawable
{   
    // Cringe moment 
    int world_map[WORLD_SIZE_H + 1][WORLD_SIZE_W + 1];

    // WHoooa!!! TILES!!
    sf::RectangleShape tiles[WORLD_SIZE_H * WORLD_SIZE_W + 1];

    // Optimization, or kostil?
    int total_tiles = 0;

    // Degeneration :D
    void generate_test_flat_world();
    void generate_tile_render_map();
public:
    // Generating new world (super flat as default)
    World();

    // Updating world
    void update();

    // Set postion of world. Test movement
    void set_position(int x, int y);

    // Vector XD
    std::vector<int> mouse_on(sf::RenderWindow& window);

    // Just switching texture of tile...
    void replace_tile(std::vector<int> position, int texture);

    // Draw it like que pro
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
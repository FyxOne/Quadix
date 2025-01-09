#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>

// Super cool config
#define WORLD_SIZE_W 75
#define WORLD_SIZE_H 46
#define TILE_SIZE 32

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

    // Set postion of world. Test movement
    void set_position(int x, int y);

    // Draw it like que pro
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
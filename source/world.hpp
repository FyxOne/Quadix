#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>

#define WORLD_SIZE_W 75
#define WORLD_SIZE_H 46
#define TILE_SIZE 32

struct tile_textures
{
    static sf::Texture dirt;
    static sf::Texture grass;
    static sf::Texture stone;

    static void initialize();
};

class World : public sf::Drawable
{   
    int world_map[WORLD_SIZE_H + 1][WORLD_SIZE_W + 1];

    sf::RectangleShape tiles[WORLD_SIZE_H * WORLD_SIZE_W + 1];
    int total_tiles = 0;

    void generate_test_flat_world();
    void generate_tile_render_map();
public:
    World();

    void set_position(int x, int y);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
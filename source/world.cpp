#include "world.hpp"

sf::Texture tile_textures::dirt;
sf::Texture tile_textures::grass;
sf::Texture tile_textures::stone;

void tile_textures::initialize()
{
    dirt.loadFromFile("resources/dirt.png");
    grass.loadFromFile("resources/grass.png");
    stone.loadFromFile("resources/stone.png");
}

void World::generate_test_flat_world()
{
    for(int height = 0; height <= WORLD_SIZE_H; height++)
    {
        for(int width = 0; width <= WORLD_SIZE_W; width++)
        {
            // shit happens sometimes
            if(height <= 10)
            {
                world_map[height][width] = 0;
            }

            // shit happens sometimes again
            else if(height == 11)
            {
                world_map[height][width] = 1;
            }

            // shit happens sometimes again x2
            else if(height >= 12 && !(height >= 14))
            {
                world_map[height][width] = 2;
            }

            // shit happens sometimes again x3
            else if(height >= 14)
            {
                world_map[height][width] = 3;
            }
        }
    }
}

void World::generate_tile_render_map()
{
    int y = 0;
    for(int height = 0; height <= WORLD_SIZE_H; height++)
    {
        int x = 0;
        for(int width = 0; width <= WORLD_SIZE_W; width++)
        {
            if(world_map[height][width] == 0)
            {
                
            }

            else 
            {
                tiles[total_tiles].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                tiles[total_tiles].setPosition(x, y);

                // adding texture
                switch (world_map[height][width])
                {
                    case 1:
                        tiles[total_tiles].setTexture(&tile_textures::grass);
                        break;
                    case 2:
                        tiles[total_tiles].setTexture(&tile_textures::dirt);
                        break;
                    case 3:
                        tiles[total_tiles].setTexture(&tile_textures::stone);
                        break;

                    default:
                        break;
                }

                total_tiles++;
            }

            x += TILE_SIZE;
        }

        y += TILE_SIZE;
    }
}

World::World()
{
    generate_test_flat_world();
    generate_tile_render_map();
}

void World::set_position(int x, int y)
{
    for(int tilec = 0; tilec <= total_tiles; tilec++)
    {
        tiles[tilec].setPosition(tiles[tilec].getPosition().x + x, tiles[tilec].getPosition().y + y);
    }
}

void World::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(int tilec = 0; tilec <= total_tiles; tilec++)
    {
        target.draw(tiles[tilec]);
    }
}

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
                world_map[height][width] = TEXTURE_AIR;
            }

            // shit happens sometimes again
            else if(height == 11)
            {
                world_map[height][width] = TEXTURE_GRASS;
            }

            // shit happens sometimes again x2
            else if(height >= 12 && !(height >= 14))
            {
                world_map[height][width] = TEXTURE_DIRT;
            }

            // shit
            else if(height >= 14)
            {
                world_map[height][width] = TEXTURE_STONE;
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
                    case TEXTURE_GRASS:
                        tiles[total_tiles].setTexture(&tile_textures::grass);
                        break;
                    case TEXTURE_DIRT:
                        tiles[total_tiles].setTexture(&tile_textures::dirt);
                        break;
                    case TEXTURE_STONE:
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

void World::update()
{
    total_tiles = 0;

   generate_tile_render_map();
}

void World::set_position(int x, int y)
{
    for(int tilec = 0; tilec <= total_tiles; tilec++)
    {
        tiles[tilec].setPosition(tiles[tilec].getPosition().x + x, tiles[tilec].getPosition().y + y);
    }
}

std::vector<int> World::mouse_on(sf::RenderWindow &window)
{
    int mouse_x = sf::Mouse::getPosition(window).x;
    int mouse_y = sf::Mouse::getPosition(window).y;

    int divisions_x = mouse_x / TILE_SIZE;
    int divisions_y = mouse_y / TILE_SIZE;

    return {divisions_x, divisions_y};
}

void World::replace_tile(std::vector<int> position, int texture)
{
    world_map[position[1]][position[0]] = texture;
}

void World::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(int tilec = 0; tilec <= total_tiles; tilec++)
    {
        target.draw(tiles[tilec]);
    }
}

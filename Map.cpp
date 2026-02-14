#include "Map.h"
#include "Constants.h"
#include <iostream>
#include <random>

Map::Map(): map(sf::PrimitiveType::Triangles, GameConstants::MAP_HEIGHT * GameConstants::MAP_WIDTH * 6) 
{
    if (!floor1.loadFromFile("forest_.png"))
    {
        std::cout << "Failed to load floor_1.png\n";
    }

    initializeMap();
}

Map::~Map()
{

}

void Map::render(sf::RenderTarget* target)
{
    target->draw(map, &floor1);
}

void Map::initializeMap()
{  
    tileSet.resize(GameConstants::MAP_HEIGHT, std::vector<int>(GameConstants::MAP_WIDTH, 0));

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, 1);

    for (int i = 0; i < GameConstants::MAP_HEIGHT; i++){
        for (int j = 0; j < GameConstants::MAP_WIDTH; j++){
            tileSet[i][j] = (dist(gen) == 0) ? 1 : 5;
        }
    }

    for (int i = 0; i < GameConstants::MAP_HEIGHT; i++){
        for (int j = 0; j < GameConstants::MAP_WIDTH; j++){
            float xPos = GameConstants::TILE_SIZE * j;
            float yPos = GameConstants::TILE_SIZE * i;

            sf::Vector2f texturePos1(160, 16);
            sf::Vector2f texturePos2(160, 47);
            sf::Vector2f texturePos3(191, 16);

            sf::Vector2f texturePos4(161, 47);
            sf::Vector2f texturePos5(191, 47);
            sf::Vector2f texturePos6(191, 16);

            map.append(sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color::White,texturePos1)); // Top-Left
            map.append(sf::Vertex(sf::Vector2f(xPos, yPos + GameConstants::TILE_SIZE), sf::Color::White, texturePos2)); // Bottom-Left
            map.append(sf::Vertex(sf::Vector2f(xPos + GameConstants::TILE_SIZE, yPos), sf::Color::White, texturePos3)); // Top-Right

            map.append(sf::Vertex(sf::Vector2f(xPos, yPos + GameConstants::TILE_SIZE), sf::Color::White, texturePos4)); // Bottom-Left
            map.append(sf::Vertex(sf::Vector2f(xPos + GameConstants::TILE_SIZE, yPos + GameConstants::TILE_SIZE), sf::Color::White, texturePos5)); // Bottom-Right
            map.append(sf::Vertex(sf::Vector2f(xPos + GameConstants::TILE_SIZE, yPos), sf::Color::White, texturePos6)); // Top-Right
        }
    }

}

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.h"

class Map{
    public:
        Map();
        ~Map();

        void update();
        void render(sf::RenderTarget* target);

    private:
        // Map
        std::vector<std::vector<int>> tileSet;
        sf::VertexArray map;

        void initializeMap();

        // Texture
        sf::Texture floor1;
};
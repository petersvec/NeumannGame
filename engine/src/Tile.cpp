#include "../include/Tile.hpp"

#include <stdlib.h>

#include <SFML/Graphics.hpp>

#include <iostream>


namespace engine {
    Tile::Tile() {
        srand(time(NULL));
        sprite.setScale(sf::Vector2f(1, 1));
        

    }
    Tile::Tile(int tilesize) {
        srand(time(NULL));
        //sprite.setScale(sf::Vector2f(tilesize, tilesize));

    }
}
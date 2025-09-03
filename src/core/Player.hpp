#pragma once
#include <SFML/Graphics.hpp>

class Map;

class Player {
public:
    sf::Vector2f pos{6.5f, 6.5f}; // em tiles
    float angle{0.0f};            // radianos

    // configurações de movimento
    float moveSpeed{3.0f};  // tiles/seg
    float rotSpeed{2.5f};   // rad/seg

    void update(float dt, const Map& map);
};

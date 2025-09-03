#pragma once
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "Player.hpp"

class Renderer2D {
public:
    explicit Renderer2D(float tileSize = 32.f);
    void draw(sf::RenderTarget& target, const Map& map, const Player* player = nullptr);

private:
    float tile_;
};

#include "Renderer2D.hpp"
#include <cmath>

Renderer2D::Renderer2D(float tileSize) : tile_(tileSize) {}

void Renderer2D::draw(sf::RenderTarget& target, const Map& map, const Player* player) {
    // fundo
    sf::RectangleShape bg({map.W * tile_, map.H * tile_});
    bg.setPosition(0.f, 0.f);
    bg.setFillColor(sf::Color(20,20,22));
    target.draw(bg);

    // células
    sf::RectangleShape cell({tile_-1.f, tile_-1.f});
    for (int y = 0; y < Map::H; ++y) {
        for (int x = 0; x < Map::W; ++x) {
            cell.setPosition(x * tile_, y * tile_);
            cell.setFillColor(map.grid[y][x] == '1' ? sf::Color(80,80,80)
                                                    : sf::Color(35,35,35));
            target.draw(cell);
        }
    }

    // player (opcional)
    if (player) {
        // corpo
        sf::CircleShape p(6.f);
        p.setOrigin(6.f,6.f);
        p.setFillColor(sf::Color::Yellow);
        p.setPosition(player->pos.x * tile_, player->pos.y * tile_);
        target.draw(p);

        // direção
        sf::Vertex dir[2];
        dir[0] = sf::Vertex(p.getPosition(), sf::Color::Yellow);
        sf::Vector2f tip = p.getPosition()
                         + sf::Vector2f(std::cos(player->angle), std::sin(player->angle)) * 20.f;
        dir[1] = sf::Vertex(tip, sf::Color::Yellow);
        target.draw(dir, 2, sf::Lines);
    }
}

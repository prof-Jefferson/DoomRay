#include "Player.hpp"
#include "Map.hpp"
#include <cmath>

// evita atravessar paredes
static bool canMoveTo(const Map& map, float nx, float ny) {
    int gx = (int)std::floor(nx);
    int gy = (int)std::floor(ny);
    if (gx < 0 || gx >= Map::W || gy < 0 || gy >= Map::H) return false;
    return !map.isWall(gx, gy);
}

void Player::update(float dt, const Map& map) {
    // input
    float fwd = 0.f;   // W/S
    float str = 0.f;   // A/D
    float rot = 0.f;   // ←/→

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) fwd += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) fwd -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) str -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) str += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  rot -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) rot += 1.f;

    angle += rot * rotSpeed * dt;

    // vetor frente e direita
    float ca = std::cos(angle), sa = std::sin(angle);
    sf::Vector2f dirF(ca, sa);
    sf::Vector2f dirR(-sa, ca);

    sf::Vector2f delta = (fwd * moveSpeed * dt) * dirF + (str * moveSpeed * dt) * dirR;

    // colisão separada por eixo (desliza nas paredes)
    float nx = pos.x + delta.x;
    if (canMoveTo(map, nx, pos.y)) pos.x = nx;

    float ny = pos.y + delta.y;
    if (canMoveTo(map, pos.x, ny)) pos.y = ny;
}

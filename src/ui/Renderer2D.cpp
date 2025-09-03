#include "Renderer2D.hpp"

Renderer2D::Renderer2D(float tileSize) : tile_(tileSize) {}

void Renderer2D::draw(sf::RenderTarget& target, const Map& map) {
    // fundo do painel 2D
    sf::RectangleShape bg({map.W * tile_, map.H * tile_});
    bg.setPosition(0.f, 0.f);
    bg.setFillColor(sf::Color(20,20,22));
    target.draw(bg);

    // células do mapa
    sf::RectangleShape cell({tile_-1.f, tile_-1.f});
    for (int y = 0; y < Map::H; ++y) {
        for (int x = 0; x < Map::W; ++x) {
            cell.setPosition(x * tile_, y * tile_);
            if (map.grid[y][x] == '1')
                cell.setFillColor(sf::Color(80,80,80));
            else
                cell.setFillColor(sf::Color(35,35,35));
            target.draw(cell);
        }
    }

    // (opcional) grade leve
    /*
    sf::Vertex lines[2];
    for (int x=0; x<=Map::W; ++x) {
        lines[0] = {{x*tile_, 0.f}, sf::Color(50,50,50)};
        lines[1] = {{x*tile_, Map::H*tile_}, sf::Color(50,50,50)};
        target.draw(lines, 2, sf::Lines);
    }
    for (int y=0; y<=Map::H; ++y) {
        lines[0] = {{0.f, y*tile_}, sf::Color(50,50,50)};
        lines[1] = {{Map::W*tile_, y*tile_}, sf::Color(50,50,50)};
        target.draw(lines, 2, sf::Lines);
    }
    */
}

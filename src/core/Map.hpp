#pragma once
#include <array>
#include <string>

class Map {
public:
    static constexpr int W = 16;
    static constexpr int H = 16;

    // '1' = parede, '0' = vazio
    std::array<std::string, H> grid;

    static Map classic();           // fábrica de um labirinto fixo
    bool isWall(int x, int y) const;
};

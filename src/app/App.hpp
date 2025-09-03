#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "TextPanel.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Renderer2D.hpp"

class App {
public:
    App();
    void run();

private:
    sf::RenderWindow window_;
    sf::View viewLeft_, viewRight_;
    float panelW_{0.f}, winW_{0.f}, winH_{0.f};
    sf::Font font_;

    // esquerda: mapa + player
    Map        map_;
    Player     player_;
    Renderer2D r2d_{32.f};

    // direita: placeholder
    std::unique_ptr<TextPanel> rightPanel_;

    void handleEvents();
    void draw();
};

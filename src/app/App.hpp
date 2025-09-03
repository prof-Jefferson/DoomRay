#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "TextPanel.hpp"
#include "Map.hpp"
#include "Renderer2D.hpp"

class App {
public:
    App();           // configura janela fullscreen e views
    void run();      // loop principal
private:
    // janela & views
    sf::RenderWindow window_;
    sf::View viewLeft_;
    sf::View viewRight_;
    float panelW_{0.f}, winW_{0.f}, winH_{0.f};

    // recursos
    sf::Font font_;

    // ESQUERDA: labirinto 2D
    Map        map_;
    Renderer2D r2d_{32.f};

    // DIREITA: placeholder (texto)
    std::unique_ptr<TextPanel> rightPanel_;

    // helpers
    void handleEvents();
    void draw();
};

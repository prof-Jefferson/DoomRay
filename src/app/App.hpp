#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "TextPanel.hpp"

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

    // painéis de texto
    std::unique_ptr<TextPanel> leftPanel_;
    std::unique_ptr<TextPanel> rightPanel_;

    // helpers
    void handleEvents();
    void draw();
};

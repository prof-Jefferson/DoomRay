#include "App.hpp"
#include "Map.hpp"
#include <iostream>

static const char* kFontPath = "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf";

App::App() {
    auto desktop = sf::VideoMode::getDesktopMode();
    winW_ = static_cast<float>(desktop.width);
    winH_ = static_cast<float>(desktop.height);
    panelW_ = winW_ * 0.5f;

    window_.create(desktop, "DoomRay - 2D Map (left) | placeholder (right)", sf::Style::Fullscreen);
    window_.setFramerateLimit(60);

    viewLeft_  = sf::View(sf::FloatRect(0.f, 0.f, panelW_, winH_));
    viewRight_ = sf::View(sf::FloatRect(0.f, 0.f, panelW_, winH_));
    viewLeft_.setViewport (sf::FloatRect(0.f,  0.f, 0.5f, 1.f));
    viewRight_.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));

    if (!font_.loadFromFile(kFontPath)) {
        std::cerr << "Erro: nao consegui carregar a fonte: " << kFontPath << "\n";
    }

    // mapa fixo
    map_ = Map::classic();

    // painel direito: mantém texto
    rightPanel_ = std::make_unique<TextPanel>(
        TextPanel::Spec{ .utf8 = "Viewport 3D (em breve)",
                         .size = 48u,
                         .color = sf::Color(180, 220, 255),
                         .center = { panelW_/2.f, winH_/2.f },
                         .bg = sf::Color(18,18,22) },
        font_);
}

void App::run() {
    while (window_.isOpen()) {
        handleEvents();
        draw();
    }
}

void App::handleEvents() {
    sf::Event e;
    while (window_.pollEvent(e)) {
        if (e.type == sf::Event::Closed ||
           (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)) {
            window_.close();
        }
    }
}

void App::draw() {
    window_.clear(sf::Color::Black);

    // esquerda: labirinto 2D
    window_.setView(viewLeft_);
    r2d_.draw(window_, map_);

    // direita: permanece o texto (placeholder)
    window_.setView(viewRight_);
    rightPanel_->draw(window_);

    window_.display();
}

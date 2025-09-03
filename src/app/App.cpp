#include "App.hpp"
#include <iostream>

// caminho de fonte do sistema (pode mover para assets/ depois)
static const char* kFontPath = "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf";

App::App() {
    // janela fullscreen
    auto desktop = sf::VideoMode::getDesktopMode();
    winW_ = static_cast<float>(desktop.width);
    winH_ = static_cast<float>(desktop.height);
    panelW_ = winW_ * 0.5f;

    window_.create(desktop, "DoomRay - POO (duas views)", sf::Style::Fullscreen);
    window_.setFramerateLimit(60);

    // views: cada view tem "mundo" do tamanho do seu painel
    viewLeft_  = sf::View(sf::FloatRect(0.f, 0.f, panelW_, winH_));
    viewRight_ = sf::View(sf::FloatRect(0.f, 0.f, panelW_, winH_));
    viewLeft_.setViewport (sf::FloatRect(0.f,  0.f, 0.5f, 1.f));
    viewRight_.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));

    // fonte
    if (!font_.loadFromFile(kFontPath)) {
        std::cerr << "Erro: nao consegui carregar a fonte: " << kFontPath << "\n";
    }

    // painéis: mensagens centralizadas
    leftPanel_  = std::make_unique<TextPanel>(
        TextPanel::Spec{ .utf8 = "Hello World!",
                         .size = 72u,
                         .color = sf::Color::Yellow,
                         .center = { panelW_/2.f, winH_/2.f },
                         .bg = sf::Color(30,30,34) },
        font_
    );

    rightPanel_ = std::make_unique<TextPanel>(
        TextPanel::Spec{ .utf8 = "Olá Mundo!", .size = 72u,
                        .color = sf::Color::Cyan,
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

    // painel esquerdo
    window_.setView(viewLeft_);
    leftPanel_->draw(window_);

    // painel direito
    window_.setView(viewRight_);
    rightPanel_->draw(window_);

    window_.display();
}

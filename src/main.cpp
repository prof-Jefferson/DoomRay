#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // pega resolução do monitor
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // cria a janela em tela cheia
    sf::RenderWindow window(desktop, "DoomRay - Fullscreen Hello World",
                            sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    // carrega a fonte (ajuste o caminho se necessário)
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf")) {
        std::cerr << "Erro: não consegui carregar a fonte!\n";
        return 1;
    }

    // cria o texto
    sf::Text text;
    text.setFont(font);
    text.setString("Hello World!");
    text.setCharacterSize(96);             // bem grande para tela cheia
    text.setFillColor(sf::Color::Yellow);

    // centraliza o texto
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    text.setPosition(desktop.width / 2.f, desktop.height / 2.f);

    // loop principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close(); // sai no ESC
            }
        }

        window.clear(sf::Color(20,20,20));
        window.draw(text);
        window.display();
    }

    return 0;
}

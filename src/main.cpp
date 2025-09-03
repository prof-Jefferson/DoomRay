#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <string_view>

// Converte UTF-8 (char) para sf::String
static sf::String toSfStringUtf8(std::string_view utf8) {
    return sf::String::fromUtf8(utf8.begin(), utf8.end());
}
// Converte UTF-8 (char8_t) para sf::String
static sf::String toSfStringUtf8(std::u8string_view utf8) {
    const char* begin = reinterpret_cast<const char*>(utf8.data());
    const char* end   = begin + utf8.size();
    return sf::String::fromUtf8(begin, end);
}

// helper: cria sf::Text a partir de UTF-8 e centraliza no ponto informado
static sf::Text makeTextUtf8(std::u8string_view utf8, const sf::Font& font,
                             unsigned size, sf::Color color, sf::Vector2f center)
{
    sf::Text t;
    t.setFont(font);
    t.setCharacterSize(size);
    t.setFillColor(color);

    t.setString(toSfStringUtf8(utf8)); // aceita u8"..."
    sf::FloatRect b = t.getLocalBounds();
    t.setOrigin(b.width/2.f, b.height/2.f);
    t.setPosition(center);
    return t;
}

// overload para também aceitar std::string/std::string_view UTF-8
static sf::Text makeTextUtf8(std::string_view utf8, const sf::Font& font,
                             unsigned size, sf::Color color, sf::Vector2f center)
{
    sf::Text t;
    t.setFont(font);
    t.setCharacterSize(size);
    t.setFillColor(color);

    t.setString(toSfStringUtf8(utf8)); // aceita "..." (fonte do arquivo em UTF-8)
    sf::FloatRect b = t.getLocalBounds();
    t.setOrigin(b.width/2.f, b.height/2.f);
    t.setPosition(center);
    return t;
}

int main() {
    // modo de vídeo do desktop (fullscreen)
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "DoomRay - Duas Views", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    // fonte
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf")) {
        std::cerr << "Erro: não consegui carregar a fonte!\n";
        return 1;
    }

    // dimensões
    const float WIN_W = static_cast<float>(desktop.width);
    const float WIN_H = static_cast<float>(desktop.height);
    const float PANEL_W = WIN_W * 0.5f;

    // views
    sf::View viewLeft (sf::FloatRect(0.f, 0.f, PANEL_W, WIN_H));
    sf::View viewRight(sf::FloatRect(0.f, 0.f, PANEL_W, WIN_H));
    viewLeft.setViewport (sf::FloatRect(0.f,  0.f, 0.5f, 1.f));
    viewRight.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));

    // fundos
    sf::RectangleShape leftBg ({PANEL_W, WIN_H});  leftBg.setFillColor(sf::Color(30,30,34));
    sf::RectangleShape rightBg({PANEL_W, WIN_H});  rightBg.setFillColor(sf::Color(18,18,22));
    leftBg.setPosition(0.f, 0.f); rightBg.setPosition(0.f, 0.f);

    // textos (agora u8 funciona e também literais normais)
    sf::Text leftText  = makeTextUtf8(u8"Hello World!", font, 72, sf::Color::Yellow,
                                      {PANEL_W/2.f, WIN_H/2.f});
    sf::Text rightText = makeTextUtf8(u8"Olá Mundo!",   font, 72, sf::Color::Cyan,
                                      {PANEL_W/2.f, WIN_H/2.f});

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed ||
               (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        // painel esquerdo
        window.setView(viewLeft);
        window.draw(leftBg);
        window.draw(leftText);

        // painel direito
        window.setView(viewRight);
        window.draw(rightBg);
        window.draw(rightText);

        window.display();
    }

    return 0;
}

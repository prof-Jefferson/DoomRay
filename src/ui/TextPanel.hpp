#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextPanel {
public:
    struct Spec {
        std::string utf8;     // mensagem em UTF-8 (acentos ok)
        unsigned size{48};    // tamanho da fonte
        sf::Color color{sf::Color::White};
        sf::Vector2f center{0.f, 0.f}; // ponto onde centralizar
        sf::Color bg{sf::Color(20,20,20)}; // cor do fundo do painel
        sf::Vector2f bgSize{0.f, 0.f};     // opcional (0 = inferir)
    };

    TextPanel(const Spec& spec, const sf::Font& font);

    void setText(const std::string& utf8); // trocar mensagem
    void draw(sf::RenderTarget& target) const;

private:
    sf::Text text_;
    sf::RectangleShape bg_;
    Spec spec_;
    void center_(); // centraliza baseado nos bounds do texto
};

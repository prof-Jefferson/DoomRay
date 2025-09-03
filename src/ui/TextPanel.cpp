#include "TextPanel.hpp"

static sf::String toSfStringUtf8(const std::string& s) {
    return sf::String::fromUtf8(s.begin(), s.end());
}

TextPanel::TextPanel(const Spec& spec, const sf::Font& font)
: spec_(spec) {
    // fundo
    bg_.setFillColor(spec_.bg);
    if (spec_.bgSize.x > 0.f && spec_.bgSize.y > 0.f)
        bg_.setSize(spec_.bgSize);
    else
        bg_.setSize({ spec_.center.x * 2.f, spec_.center.y * 2.f }); // assume painel inteiro

    bg_.setPosition(0.f, 0.f);

    // texto
    text_.setFont(font);
    text_.setCharacterSize(spec_.size);
    text_.setFillColor(spec_.color);
    text_.setString(toSfStringUtf8(spec_.utf8));
    center_();
}

void TextPanel::setText(const std::string& utf8) {
    spec_.utf8 = utf8;
    text_.setString(toSfStringUtf8(spec_.utf8));
    center_();
}

void TextPanel::center_() {
    sf::FloatRect b = text_.getLocalBounds();
    text_.setOrigin(b.width/2.f, b.height/2.f);
    text_.setPosition(spec_.center);
}

void TextPanel::draw(sf::RenderTarget& target) const {
    target.draw(bg_);
    target.draw(text_);
}

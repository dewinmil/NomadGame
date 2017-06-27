#pragma once
#include <SFML/Graphics.hpp>

    struct Button{
      sf::Sprite buttonBackground;
      sf::Text buttonText;
    };

    Button createButton (sf::Sprite* buttonSprite, sf::Text* text, sf::Font* font, sf::Image* buttonDefaultImage, sf::Texture* buttonDefaultTexture, std::string string, sf::Color textColor, sf::Color buttonColor, int x, int y, int textSize, int width, int height);
    sf::Sprite createRect (sf::Sprite* buttonSprite, sf::Image* image, sf::Texture* texture, sf::Color buttonColor, int x, int y, int width, int height);
    sf::Text createText (sf::Text* text, sf::Font* font, std::string string, sf::Color color, int x, int y, int size);

#include "Button.h"


Button createButton(sf::Sprite* buttonSprite, sf::Text* text, sf::Font* font, sf::Image* image, sf::Texture* texture, std::string string, sf::Color textColor, sf::Color buttonColor, int x, int y, int textSize, int width, int height) {
    sf::FloatRect localBounds;
    text->setFont(*font);
    text->setCharacterSize(textSize);
    text->setString(string);
    text->setColor(textColor);
    localBounds = text->getLocalBounds();
    text->setOrigin(localBounds.left + localBounds.width/2.0f, localBounds.top  + localBounds.height/2.0f); //center text origin
    text->setPosition(x, y);

    image->create(width, height, buttonColor);
    texture->loadFromImage(*image);
    //buttonDefaultTexture.create(width, height);
    //buttonDefaultTexture.update(buttonDefaultImage);
    buttonSprite->setTexture(*texture);
    localBounds = buttonSprite->getLocalBounds();
    buttonSprite->setOrigin(localBounds.left + localBounds.width/2.0f, localBounds.top  + localBounds.height/2.0f);
    buttonSprite->setPosition(x, y);

    Button button;
    button.buttonBackground = *buttonSprite;
    button.buttonText = *text;
    return button;

}

sf::Sprite createRect (sf::Sprite* buttonSprite, sf::Image* image, sf::Texture* texture, sf::Color buttonColor, int x, int y, int width, int height){
    sf::FloatRect localBounds;

    image->create(width, height, buttonColor);
    texture->loadFromImage(*image);
    //buttonDefaultTexture.create(width, height);
    //buttonDefaultTexture.update(buttonDefaultImage);
    buttonSprite->setTexture(*texture);
    localBounds = buttonSprite->getLocalBounds();
    buttonSprite->setOrigin(localBounds.left + localBounds.width/2.0f, localBounds.top  + localBounds.height/2.0f);
    buttonSprite->setPosition(x, y);

    return *buttonSprite;
}


sf::Text createText(sf::Text* text, sf::Font* font, std::string string, sf::Color color, int x, int y, int textSize) {
    sf::FloatRect localBounds;
    text->setFont(*font);
    text->setCharacterSize(textSize);
    text->setString(string);
    text->setColor(color);
    localBounds = text->getLocalBounds();
    text->setOrigin(localBounds.left + localBounds.width/2.0f, localBounds.top  + localBounds.height/2.0f); //center text origin
    text->setPosition(x, y);

    return *text;
}

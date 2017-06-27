#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

#define MAX_ITEMS 3

class Menu{

public:
  Menu(int width, int height);

  ~Menu();

  void draw(sf::RenderWindow &window);

  void MoveUp();
  void MoveDown();

private:
  int SelectedItemIndex;
  sf::Font font;
  Button menu[MAX_ITEMS];
  sf::Sprite buttonSprite;
  sf::Text text;
  sf::Font abyssinica;
  sf::Image image;
  sf::Texture texture;



};

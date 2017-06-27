#include <SFML/Graphics.hpp>
#include <X11/Xlib.h>
#include <iostream>
#include <stdint.h>
#include "Button.h"
#include "Menu.h"

int main()
{
  int windowHeight = 0;
  int windowWidth = 0;
  Display* d = XOpenDisplay(NULL);
  Screen*  s = DefaultScreenOfDisplay(d);

  windowWidth = s->width;
  windowHeight = s->height;

  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Nomads", sf::Style::Fullscreen);
  sf::Mouse mouse;

  sf::Sprite buttonSprite;
  sf::Color red(255,0,0);
  sf::Color green(0,0,255);
  sf::Color blue(0,0,255);
  sf::Color gray(169,169,169);
  sf::Text text;
  sf::Font abyssinica;
  sf::Image image;
  sf::Texture texture;
  bool press = false;

  //sf::FloatRect localBounds;


  abyssinica.loadFromFile("/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-R.ttf");

  Menu menu(windowWidth, windowHeight);



  //createButton(&buttonSprite, &text, &abyssinica, &image, &texture, "Hello World", blue, gray, windowWidth/2, windowHeight/2, 30, 300, 100);
  //createRect(&buttonSprite, &image, &texture, gray, windowWidth/2, windowHeight/2, 300, 100);
  //createText(&text, &abyssinica, "Hello World", blue, windowWidth/2, windowHeight/2, 30);

  while (window.isOpen()){
    sf::Event event;

    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed)
        window.close();
      }
      if (event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }

      if(mouse.isButtonPressed(sf::Mouse::Left) && press == true){
        if(menu.isClicked(mouse.getPosition().x, mouse.getPosition().y) == 0){
          std::cout << "Hello World1!" << std::endl;
        } else if (menu.isClicked(mouse.getPosition().x, mouse.getPosition().y) == 1){
          std::cout << "Hello World2!" << std::endl;
        } else if (menu.isClicked(mouse.getPosition().x, mouse.getPosition().y) == 2){
          std::cout << "Hello World3!" << std::endl;
        }
      }
      if(press == true){
        press = false;
      }
      if(!mouse.isButtonPressed(sf::Mouse::Left)){
        press = true;
      }



      window.clear();
      menu.draw(window);
      //window.draw(buttonSprite);
      //window.draw(text);
      window.display();
    }

    return 0;
}

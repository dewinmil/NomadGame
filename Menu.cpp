#include "Menu.h"


Menu::Menu(int width, int height){


  sf::Color red(255,0,0);
  sf::Color green(0,0,255);
  sf::Color blue(0,0,255);
  sf::Color gray(169,169,169);

  //Note to change number of menu items change max_items in .h file.

  if(!abyssinica.loadFromFile("/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-R.ttf")){
    //handle error
  }

  menu[0] = createButton(&buttonSprite, &text, &abyssinica, &image, &texture, "Play", blue, gray, width/2, height/(MAX_ITEMS + 1) *1, 30, width/3, height/9);
  menu[1] = createButton(&buttonSprite, &text, &abyssinica, &image, &texture, "Options", blue, gray, width/2, height/(MAX_ITEMS + 1) *2, 30, width/3, height/9);
  menu[2] = createButton(&buttonSprite, &text, &abyssinica, &image, &texture, "Exit", blue, gray, width/2, height/(MAX_ITEMS + 1) *3, 30, width/3, height/9);

}


void Menu::draw(sf::RenderWindow &window){

  for(int i = 0; i < MAX_ITEMS; i++){
    window.draw(menu[i].buttonBackground);
    window.draw(menu[i].buttonText);
  }

}

int Menu::isClicked(int x, int y){

  for(int i = 0; i < MAX_ITEMS; i++){
    bounds = menu[i].buttonBackground.getGlobalBounds();
    if(bounds.contains(x, y)){
      return i;
    }
  }
  return -1; //not clicked
}

#ifndef Scrolling_menu_h
#define Scrolling_menu_h

#include <Arduino.h>


class Scrolling_menu
{
  public:
  Scrolling_menu(int posX, int posY, int menuSize);

  int x;
  int y;
  int _menuSize;      
  int prevSection;
  int activeSection;
  int nextSection;

  void moveLeft();
  void moveRight();

  void sanitize();
};

#endif
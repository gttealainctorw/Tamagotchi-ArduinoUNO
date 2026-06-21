#include <Arduino.h>
#include "Scrolling_menu.h"

Scrolling_menu::Scrolling_menu(int posX, int posY, int menuSize) {
  int safeSize  = (menuSize >= 3) ? menuSize : 3;
  _menuSize     = safeSize - 1;  
  x             = posX;
  y             = posY;
  prevSection   = 0;
  activeSection = 1;
  nextSection   = 2;
}


void Scrolling_menu::sanitize() {
  if (_menuSize < 2) _menuSize = 2;
  if (prevSection   < 0 || prevSection   > _menuSize) prevSection   = 0;
  if (activeSection < 0 || activeSection > _menuSize) activeSection = 1;
  if (nextSection   < 0 || nextSection   > _menuSize) nextSection   = 2;
}


void Scrolling_menu::moveRight() {
  sanitize();

  if (nextSection == _menuSize) {
    nextSection   = 0;
    activeSection++;
    prevSection++;
  } else if (activeSection == _menuSize) {
    nextSection++;
    activeSection = 0;
    prevSection++;
  } else if (prevSection == _menuSize) {
    nextSection++;
    activeSection++;
    prevSection = 0;
  } else {
    nextSection++;
    activeSection++;
    prevSection++;
  }

  sanitize();
}

void Scrolling_menu::moveLeft() {
  sanitize();

  if (prevSection == 0) {
    nextSection--;
    activeSection--;
    prevSection = _menuSize;
  } else if (activeSection == 0) {
    nextSection--;
    activeSection = _menuSize;
    prevSection--;
  } else if (nextSection == 0) {
    nextSection   = _menuSize;
    activeSection--;
    prevSection--;
  } else {
    nextSection--;
    activeSection--;
    prevSection--;
  }

  sanitize();
}
#include <Arduino.h>
#include <EEPROM.h>
#include "Alegotchi.h"

// CONSTRUCTOR SEGURIZADO
Alegotchi::Alegotchi(bool _sleeping, int _sleep, int _happiness, int _hunger, int _age, int _beardLength, int _expression, int _clothing){
  sleeping = _sleeping;
  sleep = clamp(_sleep, STAT_MIN, STAT_MAX);
  happiness = clamp(_happiness, STAT_MIN, STAT_MAX);
  hunger = clamp(_hunger, STAT_MIN, STAT_MAX);
  age = max(0, _age); // La edad no puede ser negativa
  beardLength = clamp(_beardLength, 0, 100);
  expression = clamp(_expression, 0, 5);
  clothing = clamp(_clothing, 0, CLOTHING_MAX);
}

// FUNCIÓN CLAMP: Mantiene los valores dentro de un rango seguro
int Alegotchi::clamp(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

// SLEEP/WAKE-UP FUNCTION
void Alegotchi::updateSleeping(){
  sleeping = !sleeping;
  // Usamos EEPROM.update para no desgastar la memoria si el valor es el mismo
  EEPROM.update(ADDR_SLEEPING, (uint8_t)sleeping);
}

//__________________________________ UPDATE STATS FUNCTIONS

void Alegotchi::updateSleep(int sleepVal){
  sleep = clamp(sleep + sleepVal, STAT_MIN, STAT_MAX);
  EEPROM.update(ADDR_SLEEP, (uint8_t)sleep);
}

void Alegotchi::updateHappiness(int happinessVal){
  happiness = clamp(happiness + happinessVal, STAT_MIN, STAT_MAX);
  EEPROM.update(ADDR_HAPPINESS, (uint8_t)happiness);
}

void Alegotchi::updateHunger(int hungerVal){
  hunger = clamp(hunger + hungerVal, STAT_MIN, STAT_MAX);
  EEPROM.update(ADDR_HUNGER, (uint8_t)hunger);
}

//__________________________________ UPDATE APPEARANCE FUNCTIONS

void Alegotchi::updateAge(){
  age++;
  EEPROM.put(ADDR_AGE, age); // 'put' maneja variables de más de 1 byte (int)
}

void Alegotchi::updateBeardLength(int newBeardLength){
  beardLength = clamp(newBeardLength, 0, 100); // Asumiendo 100 como longitud máxima de barba
  EEPROM.update(ADDR_BEARD, (uint8_t)beardLength);
}

void Alegotchi::updateExpression(int newExpression){
  expression = clamp(newExpression, 0, 5);
  EEPROM.update(ADDR_EXPRESSION, (uint8_t)expression);
}

void Alegotchi::updateClothing(int newClothing){
  clothing = clamp(newClothing, 0, CLOTHING_MAX);
  EEPROM.update(ADDR_CLOTHING, (uint8_t)clothing);
}

int Alegotchi::mapValue(int val, int barLength){
  int safeVal = clamp(val, STAT_MIN, STAT_MAX);
  // Escala el valor a la longitud de la barra de la pantalla OLED
  return map(safeVal, STAT_MIN, STAT_MAX, 0, barLength);
}
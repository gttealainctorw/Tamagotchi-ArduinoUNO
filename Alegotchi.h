#ifndef Alegotchi_h
#define Alegotchi_h

#include <Arduino.h>

// --- Direcciones de memoria EEPROM ---
#define ADDR_SLEEPING   0
#define ADDR_SLEEP      1
#define ADDR_HAPPINESS  2
#define ADDR_HUNGER     3
#define ADDR_BEARD      5
#define ADDR_EXPRESSION 6
#define ADDR_CLOTHING   7
#define ADDR_AGE        10

// --- Límites de estadísticas (Clamping) ---
#define STAT_MIN        0
#define STAT_MAX        27
#define CLOTHING_MAX    3

class Alegotchi
{
  public:
    Alegotchi(bool _sleeping, int _sleep, int _happiness, int _hunger, int _age, int _beardLength, int _expression, int _clothing);

    bool sleeping; 
    
    int sleep; 
    int happiness; 
    int hunger; 

    int age; 
    int beardLength; 
    int expression; 
    int clothing; 

    // Funciones principales
    void updateSleeping();
    void updateSleep(int sleepVal);
    void updateHappiness(int happinessVal);
    void updateHunger(int hungerVal);
    void updateAge();
    void updateBeardLength(int newBeardLength);
    void updateExpression(int newExpression);
    void updateClothing(int newClothing);

    int mapValue(int val, int barLength);
    
    // Función de seguridad para evitar que las estadísticas salgan de rango
    int clamp(int v, int lo, int hi);
};

#endif
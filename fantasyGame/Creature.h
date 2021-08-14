#ifndef CREATURE_H
#define CREATURE_H
#include <string>

class Creature{
protected:
    const std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_POW{};
    int m_gold{};

public:
    // Constructors
    Creature(const std::string& name, char symbol, int health, int POW, int gold);

    // Getter functions
    const std::string& getName() const;
    char getSymbol() const;
    int getHealth() const;
    int getPOW() const;
    int getGold() const;

    void reduceHealth(int dmg);
    bool isDead() const;
    void addGold(int newGold);
};

#endif
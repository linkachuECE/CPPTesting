#include "Creature.h"

// Constructors

Creature::Creature(const std::string& name, char symbol, int health, int POW, int gold)
    : m_name{name}
    , m_symbol{symbol}
    , m_health{health}
    , m_POW{POW}
    , m_gold{gold}{}

// Getter functions

const std::string& Creature::getName() const{
    return m_name;
}

char Creature::getSymbol() const{
    return m_symbol;
}

int Creature::getHealth() const{
    return m_health;
}

int Creature::getPOW() const{
    return m_POW;
}

int Creature::getGold() const{
    return m_gold;
}


void Creature::reduceHealth(int dmg){
    if (m_health >= dmg)
        m_health -= dmg;
    else
        m_health = 0;
}

bool Creature::isDead() const{
    return !m_health;
}

void Creature::addGold(int newGold){
    m_gold += newGold;
}
#include "Player.h"

Player::Player()
    : Creature("Player 1", playerSymbol, startHealth, startPow, startGold)
    , m_lvl{startLvl}
    , m_max_health{startHealth}{}

Player::Player(const std::string name)
    : Creature(name, playerSymbol, startHealth, startPow, startGold)
    , m_lvl{startLvl}
    , m_max_health{startHealth}{}


int Player::getLvl() const{
    return m_lvl;
}

int Player::getMaxHealth() const{
    return m_max_health;
}


void Player::levelUp(){
    m_lvl++;
    m_POW++;
    m_max_health += 10;
    m_health += 5;
}

bool Player::hasWon() const{
    return (m_lvl >= winLevel);
}

void Player::reset(){
    m_health = startHealth;
    m_gold = startGold;
    m_lvl = startLvl;
    m_POW = startPow;
    m_max_health = startHealth;
}
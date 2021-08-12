#ifndef PLAYER_H
#define PLAYER_H
#include "Creature.h"

constexpr int startHealth = 10;
constexpr int startGold = 0;
constexpr int startLvl = 1;
constexpr int startPow = 1;
constexpr char playerSymbol = '@';
constexpr int winLevel = 10;

class Player: public Creature{
private:
    int m_lvl{};
    int m_max_health{};

public:
    Player();
    Player(const std::string name);

    int getLvl() const;
    int getMaxHealth() const;

    void levelUp();
    bool hasWon() const;

    void reset();
};

#endif
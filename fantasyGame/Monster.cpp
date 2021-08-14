#include "Monster.h"

Monster::Monster(Type monsterType)
    : Creature(
          getDefaultCreature(monsterType).getName()
        , getDefaultCreature(monsterType).getSymbol()
        , getDefaultCreature(monsterType).getHealth()
        , getDefaultCreature(monsterType).getPOW()
        , getDefaultCreature(monsterType).getGold()
        ){}

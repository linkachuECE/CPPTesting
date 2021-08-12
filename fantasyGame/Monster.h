#ifndef MONSTER_H
#define MONSTER_H
#include "Creature.h"
#include <array>
#include <cassert>
#include <cstdlib>
#include <ctime>

class Monster: public Creature{

public:
    enum Type{
        DRAGON,
        ORC,
        SLIME,
        SKELETON,
        WEREWOLF,
        WALUIGI,
        BUNNY,
        LIZARD,

        MAX_MONSTER_TYPES
    };

    Monster(Type monsterType);

    static Type getRandomMonster(){
        return static_cast<Type>(rand() % MAX_MONSTER_TYPES);
    }

private:
    static const Creature& getDefaultCreature(Type type){
        static const std::array<Creature, static_cast<std::size_t>(Type::MAX_MONSTER_TYPES)> monsterData{
            {{"dragon", 'D', 20, 4, 100},
             {"orc", 'o', 4, 2, 25},
             {"slime", 's', 1, 1, 10},
             {"skeleton", 'S', 5, 3, 15},
             {"werewolf", 'w', 7, 3, 40},
             {"waluigi", 'W', 1000, 1000000, 1000000},
             {"bunny", 'b', 1, 1, 5},
             {"lizard", 'l', 1, 1, 5}}
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }

};

#endif
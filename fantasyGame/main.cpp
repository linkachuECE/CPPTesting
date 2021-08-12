#include <iostream>
#include <string>
#include <functional>
#include <unistd.h>
#include "Player.h"
#include "Monster.h"

namespace Message
{
    // For asking for the player's name
    std::function<std::string()> getPlayerName([]()-> std::string{
        std::string input;
        std::cout << "Enter your name: ";
        std::cin >> input;
        return input;
    });

    // For welcoming the player to the game
    std::function welcomePlayer([](Player player){
        std::cout << "Welcome, " << player.getName() << std::endl;
    });

    // For showing a new monster that has appeared 
    std::function displayNewMonster([](Monster& monster){
        std::cout << "You have encountered a " << monster.getName() 
            << " (" << monster.getSymbol() << ")" << std::endl;
    });

    // For getting user input on whether to run or fight
    std::function<bool()> runOrFight([]() -> bool {
        while(true){
            char input{};
            std::cout << "(R)un or (F)ight: ";
            std::cin >> input;
            std::cin.sync();
            
            if (input == 'r' || input == 'R')
                return false;
            else if (input == 'f' || input == 'F')
                return true;
            else
                std::cout << "Invalid input" << std::endl;
        }
    });

    // For displaying the amount of damage done
    std::function displayDamageDealt([](Monster& monster, int dmg){
        std::cout << "You hit the " << monster.getName() << " for " << dmg << " damage." << std::endl;
        usleep(2000000);
    });

    // For displaying the amount of damage received
    std::function displayDamageReceived([](Monster& monster){
        std::cout << "The " << monster.getName() << " hit you for " << monster.getPOW() << " damage." << std::endl;
        usleep(2000000);
    });

    // For displaying the amount of gold taken from a monster
    std::function displayGoldTaken([](Monster& monster){
        std::cout << "You found " << monster.getGold() << " gold." << std::endl;
    });

    // For showing that the player has leveled up
    std::function levelUp([](Player& player){
        std::cout << "You are now level " << player.getLvl() << std::endl;
        usleep(2000000);
        std::cout << "You gained 5 HP, 10 max HP, and 1 POW" << std::endl;
    });

    // For showing that the player failed to flee
    std::function failedToFlee([](){
        std::cout << "You failed to flee" << std::endl;
    });

    // For showing that the player fled successfully
    std::function fledSuccessfully([](){
        std::cout << "You fled successfully" << std::endl;
    });

    // For showing that the player died
    std::function youDied([](Player& player){
        std::cout << "You died at level " << player.getLvl() << " with " << player.getGold() << " gold." << std::endl;
    });

    std::function youWon([](){
        std::cout << "You made it to level 20 and won!" << std::endl;
    });

    std::function<bool()> askToPlayAgain([]() -> bool {
        while(true){
            char input{};
            std::cout << "Play again? (Y/N) ";
            std::cin >> input;
            std::cin.sync();
            
            if (input == 'n' || input == 'N')
                return false;
            else if (input == 'y' || input == 'Y')
                return true;
            else
                std::cout << "Invalid input" << std::endl;
        }
    });

    // For showing the player's current status
    std::function currentStatus([](Player& player){
        std::cout << "Status: " << "lvl " << player.getLvl() << '\t' 
            << player.getHealth() << '/' << player.getMaxHealth() << "HP" << "\t "
            << player.getPOW() << "POW" << "\t" 
            << player.getGold() << " gold" << std::endl << std::endl; 
    });

    std::function currentStatusWithMonster([](Player& player, Monster& monster){
        std::cout << "Status: " << "lvl " << player.getLvl() << '\t' 
            << player.getHealth() << '/' << player.getMaxHealth() << "HP" << '\t'
            << player.getPOW() << " POW" << std::endl << std::endl;
        std::cout << "You are currently being attacked by a " << monster.getName() << std::endl;
    });

    std::function resetScreen([](Player& player){
        system("clear");
        currentStatus(player);
    });

    std::function resetScreenWithMonster([](Player& player, Monster& monster){
        system("clear");
        currentStatusWithMonster(player, monster);
    });

    std::function monsterDefeated([](Monster& monster){
        std::cout << monster.getName() << " defeated!" << std::endl;
    });
    
}

namespace Action{
    void playerAttack(Player& player, Monster& monster){
        monster.reduceHealth(player.getPOW());
        Message::displayDamageDealt(monster, player.getPOW());
    }

    void monsterAttack(Player& player, Monster& monster){
        player.reduceHealth(monster.getPOW());
        Message::displayDamageReceived(monster);
    }

    void getGold(Player& player,Monster& monster){
        player.addGold(monster.getGold());
        Message::displayGoldTaken(monster);
    }
}

int main()
{
    system("clear");

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Player player1(Message::getPlayerName());

    bool playAgain{true};

    // This while loop goes until the player says to stop playing
    while(playAgain){
        bool gameEnd{};

        Message::welcomePlayer(player1);
        usleep(2000000);
        Message::resetScreen(player1);

        // This while loop goes until the player is dead or hits level 20
        while(!gameEnd){

            Monster* currentMonster = new Monster{Monster::getRandomMonster()};
            Message::displayNewMonster(*currentMonster);
            usleep(1000000);

            // This while loop goes until the monster is dead or the player runs away
            while(true){
                if(Message::runOrFight()){
                    Action::playerAttack(player1, *currentMonster);
                    if (currentMonster->isDead()){
                        Message::monsterDefeated(*currentMonster);
                        usleep(2000000);
                        Action::getGold(player1, *currentMonster);
                        usleep(2000000);
                        player1.levelUp();
                        Message::levelUp(player1);
                        usleep(2000000);
                        delete currentMonster;
                        Message::resetScreen(player1);
                        break;
                    } else {
                        Action::monsterAttack(player1, *currentMonster);
                        usleep(2000000);
                        if(!player1.isDead())
                            Message::resetScreenWithMonster(player1, *currentMonster);
                        else
                            Message::resetScreen(player1);
                    }
                } else { 
                    if((rand() % 3) != 2){
                        Message::fledSuccessfully();
                        usleep(2000000);
                        delete currentMonster;
                        Message::resetScreen(player1);
                        break;
                    } else {
                        Message::failedToFlee();
                        usleep(1000000);
                        Action::monsterAttack(player1, *currentMonster);
                        usleep(2000000);
                        if(!player1.isDead())
                            Message::resetScreenWithMonster(player1, *currentMonster);
                        else
                            Message::resetScreen(player1);
                    }
                }

                if (player1.isDead()){
                    Message::youDied(player1);
                    delete currentMonster;
                    gameEnd = true;
                    break;
                }

                if (player1.hasWon()){
                    Message::youWon();
                    delete currentMonster;
                    gameEnd = true;
                    break;
                }
            }

        }

        if (playAgain = Message::askToPlayAgain())
            player1.reset();
    }

    system("clear");
    
	return 0;
}
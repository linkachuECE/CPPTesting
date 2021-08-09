#include "headers.h"
#include <string>

using ArithmeticFunction = int(*)(int, int);

namespace arithmetic{

    int add(int num1, int num2){
        return num1 + num2;
    }

    int subtract(int num1, int num2){
        return num1 - num2;
    }

    int multiply(int num1, int num2){
        return num1 * num2;
    }

    int divide(int num1, int num2){
        return num1 / num2;
    }

    int modulo(int num1, int num2){
        return num1 % num2;
    }
}

ArithmeticFunction getArithmeticFunction(char op){
    switch(op){
        case '+':
            return arithmetic::add;
        case '-':
            return arithmetic::subtract;
        case '*':
            return arithmetic::multiply;
        case '/':
            return arithmetic::divide;
        case '%':
            return arithmetic::modulo;
    }
}

int getOperand(){
    int num{};
    while(true){
        std::string input{};
        std::cout << "Enter a number: ";
        std::getline(std::cin, input);
        std::cin.sync();

        try{
            num = std::stoi(input);
            break;
        } catch (std::invalid_argument){
            std::cout << "Invalid input" << std::endl;
        }
    }

    return num;
}

inline bool isOperator(char op){
    switch(op){
        case '+':
        case '-':
        case '/':
        case '*':
        case '%':
            return true;
        default:
            return false;
    }
}

int getOperator(){
    char o{};
    std::string input{};
    while(true){
        std::string input{};
        std::cout << "Enter an operator (+, -, /, *, or %): ";
        std::getline(std::cin, input);
        std::cin.sync();


        try{
            o = input.at(0);
            if (!isOperator(o))
                throw std::invalid_argument("");
            break;
        } catch (std::invalid_argument){
            std::cout << "Invalid input" << std::endl;
        }
    }

    return o;
}

int main (){
    int num1{}, num2{};
    char op{};
	std::cout << "Welcome to the calculator: " << std::endl;
    num1 = getOperand();
    num2 = getOperand();
    op = getOperator();

    ArithmeticFunction currentFunction{getArithmeticFunction(op)};

    std::cout << "Your result is: " << currentFunction(num1, num2) << std::endl;

    return 0;
}
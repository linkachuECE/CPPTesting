#include "headers.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "Ball.h"

int main(){
	Ball def;
	def.print();
 
	Ball blue{ "blue" };
	blue.print();
	
	Ball twenty{ 20.0 };
	twenty.print();
	
	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();
 
	return 0;
=======
=======
#include <cassert>

class Fraction{
private:
    int m_numerator{};
    int m_denominator{1};

public:
    Fraction(int numerator, int denominator){
        if (!denominator)
            throw std::runtime_error("Denominator cannot be zero");
        
        m_denominator = denominator;
        m_numerator = numerator;
    }

    ~Fraction(){}

    friend std::ostream& operator<<(std::ostream& out, Fraction& fraction){
        out << fraction.m_numerator << "/" << fraction.m_denominator;
        return out;
    }
};

>>>>>>> 913cb3e0ca7f8fa15ef8efc50a0abed33cb9dfc9

int main(){
    try{
        Fraction thisFraction{5, 2};
        std::cout << thisFraction << std::endl;
    } catch (std::runtime_error& error){
        std::cout << error.what() << std::endl;
    }

<<<<<<< HEAD
    return 0;
>>>>>>> 3e87387bb0115d8453b6c5da45c581aa2e79fd0b
=======
	return 0;
>>>>>>> 913cb3e0ca7f8fa15ef8efc50a0abed33cb9dfc9
}
#include "headers.h"
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


int main(){
    try{
        Fraction thisFraction{5, 2};
        std::cout << thisFraction << std::endl;
    } catch (std::runtime_error& error){
        std::cout << error.what() << std::endl;
    }

	return 0;
}
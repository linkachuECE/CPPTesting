#include "headers.h"
#include <string>

class Ball {
    double m_radius{};
    std::string m_color{};

public:
    Ball(double radius = 10.0, std::string color = "black"){
        m_radius = radius;
        m_color = color;
    }

    void print(){
        std::cout << "Radius: " << m_radius << "\tColor: " << m_color << std::endl;
    }

};

int main(){
    Ball ball{5.0, "White"};

    ball.print();
    return 0;
}
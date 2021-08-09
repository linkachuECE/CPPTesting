#include "headers.h"
#include "Ball.h"

    double m_radius{};
    std::string m_color{};

    Ball::Ball(double radius, std::string color){
        m_radius = radius;
        m_color = color;
    }

    void Ball::print() const {
        std::cout << "Radius: " << m_radius << "\tColor: " << m_color << std::endl;
    }

    Ball& Ball::timesRadius(int mult){
        m_radius *= mult;
        return *this;
    }

    Ball& Ball::halfRadius(){
        m_radius /= 2;
        return *this;
    }
#include "headers.h"

#include <cassert>
 
template <class T>
class Pair1{
private:
    T m_value1{}, m_value2{};

public:
    Pair1(T value1, T value2): m_value1{value1}, m_value2{value2}{}

    T first() const{ return m_value1; }
    T second() const{ return m_value2; }

};

template <class T, class U>
class Pair{
private:
    T m_value1{};
    U m_value2{};

public:
    Pair(T value1, U value2): m_value1{value1}, m_value2{value2}{}

    T first() const{ return m_value1; }
    U second() const{ return m_value2; }

};


int main()
{
	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
 
	const Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
 
	return 0;
}
#include <iostream>

using namespace std;

bool printNumTimesTwo(int);

int main(){
    int x{};
    string y{};

    cout << "enter a number: ";
    cin >> x;

    y = printNumTimesTwo(x) ? "greater than" : "less than";

    cout << "Plus, the number you entered is " << y << " than 10\n";
}

bool printNumTimesTwo(int a){
    cout << "Twice that number is: " << a * 2 << "\n";
    return a > 10 ? true : false;
}

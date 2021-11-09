#include <iostream>
#include <list>
#include <utility>
#include <map>

int main() {
   std::map<std::string, int> myMap{{"Ethan", 20}, {"yarpa", 85}};
   myMap["Ethan"] = 21;
   myMap["Mom"] = 46;

   std::cout << myMap["Ethan"] << std::endl;
   std::cout << myMap["Mom"] << std::endl;
   return 0;
}
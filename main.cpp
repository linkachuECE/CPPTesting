#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Write method to create and output all permutations of the list of names.
void AllPermutations(const vector<string> &permList, const vector<string> &nameList) {
   
}

int main(int argc, char* argv[]) {
   vector<string> nameList;
   vector<string> permList;
   string name;

   // TODO: Read in a list of names; stop when -1 is read. Then call recursive method.
   cin >> name;
   
   do{
      permList.push_back(name);
      cin >> name;
   } while (name != "-1");
   
   
   return 0;
}
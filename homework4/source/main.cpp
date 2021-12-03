#include "../include/graphNode.h"
#include "../include/graph.h"
#include <iostream>

int main(){
    Graph myGraph{};

    myGraph.addNode("U");
    myGraph.addNode("X", {{"U", 5}});
    myGraph.addNode("W", {{"U", 3}, {"X", 4}});
    myGraph.addNode("V", {{"U", 7}, {"W", 3}});
    myGraph.addNode("Y", {{"X", 7}, {"W", 8}, {"V", 4}});
    myGraph.addNode("Z", {{"Y", 2}, {"X", 9}});

    std::cout << myGraph.findShortestDistance("U","Z") << std::endl;

    return 0;
}
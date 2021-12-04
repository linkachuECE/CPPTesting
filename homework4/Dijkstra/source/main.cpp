#include "../include/graphVertex.h"
#include "../include/graph.h"
#include <iostream>

int main(){
    Graph myGraph{};

    myGraph.addVertex("U");
    myGraph.addVertex("X", {{"U", 5}});
    myGraph.addVertex("W", {{"U", 3}, {"X", 4}});
    myGraph.addVertex("V", {{"U", 7}, {"W", 3}});
    myGraph.addVertex("Y", {{"X", 7}, {"W", 8}, {"V", 4}});
    myGraph.addVertex("Z", {{"Y", 2}, {"X", 9}});

    std::cout << myGraph.getShortestPath("Z", "V") << std::endl;
    std::cout << myGraph.getShortestPath("Z", "W") << std::endl;
    std::cout << myGraph.getShortestPath("Z", "X") << std::endl;
    std::cout << myGraph.getShortestPath("Z", "Y") << std::endl;
    std::cout << myGraph.getShortestPath("Z", "U") << std::endl;


    return 0;
}
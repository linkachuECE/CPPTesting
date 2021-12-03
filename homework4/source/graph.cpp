#include "../include/graphNode.h"
#include "../include/graph.h"

#include <limits>

void Graph::addNode(const char* name){
    for (auto node : m_nodes)
        if (std::string(name) == node->getName())
            return;
    
    m_nodes.push_back(new GraphNode(name));
}

void Graph::addNode(const char* name, std::initializer_list<std::pair<const char*, double>> neighbors){
    for(auto node : m_nodes)
        if(std::string(name) == node->getName())
            return;

    std::vector<std::pair<GraphNode*, int>> neighborPointers{};
    
    for(auto neighbor : neighbors)
        for(auto node : m_nodes)
            if(node->getName() == std::string(neighbor.first))
                neighborPointers.push_back(std::make_pair(node, neighbor.second));

    m_nodes.push_back(new GraphNode(name));

    for(auto n : neighborPointers)
        m_nodes.back()->addNeighbor(n.first, n.second);
    
}

double Graph::findShortestDistance(const char* node1, const char* node2){
    GraphNode *startNode{}, *endNode{}, *currNode{};
    double finalDistance;

    for(auto node : m_nodes){
        if(node->getName() == std::string(node1))
            startNode = node;
        if(node->getName() == std::string(node2))
            endNode = node;
    }

    if(!endNode || !startNode)
        return -1;
    
    currNode = startNode;
    currNode->setDistance(0);

    while(currNode){
        double shortestDistance{std::numeric_limits<double>::infinity()};

        currNode->visit();
        currNode = nullptr;

        for(auto node : m_nodes){
            if((node->getDistance() < shortestDistance )&& !node->getVisitStatus()){
                shortestDistance = node->getDistance();
                currNode = node;
            }
        }
    }
    
    finalDistance = endNode->getDistance();

    clearNodes();

    return finalDistance;
}

void Graph::clearNodes(){
    for(auto node : m_nodes){
        node->setDistance(std::numeric_limits<double>::infinity());
        node->setPredecessor(nullptr);
    }
}

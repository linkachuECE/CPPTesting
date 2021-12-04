#include "../include/graphVertex.h"
#include "../include/graph.h"

#include <limits>
#include <sstream>

void Graph::addVertex(const char* name){
    for (auto node : m_nodes)
        if (std::string(name) == node->getName())
            return;
    
    m_nodes.push_back(new GraphVertex(name));
}

void Graph::addVertex(const char* name, std::initializer_list<std::pair<const char*, double>> neighbors){
    for(auto node : m_nodes)
        if(std::string(name) == node->getName())
            return;

    std::vector<std::pair<GraphVertex*, int>> neighborPointers{};
    
    for(auto neighbor : neighbors)
        for(auto node : m_nodes)
            if(node->getName() == std::string(neighbor.first))
                neighborPointers.push_back(std::make_pair(node, neighbor.second));

    m_nodes.push_back(new GraphVertex(name));

    for(auto n : neighborPointers)
        m_nodes.back()->addNeighbor(n.first, n.second);
    
}

GraphVertex* Graph::prepareNodes(const char* node1, const char* node2){
    GraphVertex *startNode{}, *endNode{}, *currNode{};
    double finalDistance;

    for(auto node : m_nodes){
        if(node->getName() == std::string(node1))
            startNode = node;
        if(node->getName() == std::string(node2))
            endNode = node;
    }

    if(!endNode || !startNode)
        return nullptr;
    
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

    return endNode;
}

double Graph::getShortestDistance(const char* node1, const char* node2){
    GraphVertex* endNode = prepareNodes(node1, node2);
    double finalDistance = endNode->getDistance();

    return finalDistance;
}

std::string Graph::getShortestPath(const char* node1, const char* node2){
    GraphVertex* endNode = prepareNodes(node1, node2);
    GraphVertex* currNode = endNode;

    if(!endNode)
        return std::string{"At least one of those nodes do not exist."};

    std::vector<std::string> path{};

    std::stringstream ss;

    ss << "The shortest path from " << node1 << " to " << node2 << " is: " << std::endl;

    while(currNode){
        path.push_back(currNode->getName());
        currNode = currNode->getPredecessor();
    }

    for(auto i = path.rbegin(); i < path.rend() - 1; i++)
        ss << *i << " --> ";
    
    ss << path.front();

    return ss.str();
}

void Graph::resetNodes(){
    for(auto node : m_nodes){
        node->setDistance(std::numeric_limits<double>::infinity());
        node->setPredecessor(nullptr);
    }
}

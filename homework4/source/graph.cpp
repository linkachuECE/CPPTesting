#include "../include/graphNode.h"
#include "../include/graph.h"

#include <limits>
#include <sstream>

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

GraphNode* Graph::prepareNodes(const char* node1, const char* node2){
    GraphNode *startNode{}, *endNode{}, *currNode{};
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
    GraphNode* endNode = prepareNodes(node1, node2);
    double finalDistance = endNode->getDistance();

    return finalDistance;
}

std::string Graph::getShortestPath(const char* node1, const char* node2){
    GraphNode* endNode = prepareNodes(node1, node2);
    GraphNode* currNode = endNode;

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

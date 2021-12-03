#include "../include/graphNode.h"

GraphNode::GraphNode(const char* name, std::initializer_list<std::pair<GraphNode*, double>> neighbors)
:m_name{name}{
    for (auto neighbor : neighbors){
        m_neighbors.emplace_back(neighbor.first, neighbor.second);

        if(!neighbor.first->findNeighbor(this))
            neighbor.first->addNeighbor(this, neighbor.second);
    }
}

void GraphNode::addNeighbor(GraphNode* neighbor, double distance){
    m_neighbors.emplace_back(neighbor, distance);
    if(!neighbor->findNeighbor(this))
        neighbor->addNeighbor(this, distance);
}

bool GraphNode::findNeighbor(GraphNode* node) const{
    for(auto neighbor : m_neighbors)
        if (neighbor.first == node)
            return true;
    
    return false;
}

void GraphNode::visit(){
    for(auto neighbor : m_neighbors){
        if(neighbor.first->getVisitStatus())
            continue;
        
        if(m_distanceFromSource + neighbor.second < neighbor.first->getDistance()){
            neighbor.first->setDistance(m_distanceFromSource + neighbor.second);
            neighbor.first->setPredecessor(this);
        }
    }

    m_visited = true;
}

void GraphNode::setDistance(double distance){
    m_distanceFromSource = distance;
}

void GraphNode::setPredecessor(GraphNode* pred){
    m_predecessor = pred;
}
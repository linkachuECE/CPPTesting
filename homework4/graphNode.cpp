#include "graphNode.h"

GraphNode::GraphNode(const char* name, std::initializer_list<std::pair<GraphNode*, int>> neighbors)
:m_name{name}{
    for (auto neighbor : neighbors){
        m_neighbors.emplace_back(neighbor.first, neighbor.second);

        if(!neighbor.first->findNeighbor(this))
            neighbor.first->addNeighbor(this, neighbor.second);
    }
}

void GraphNode::addNeighbor(GraphNode* neighbor, int distance){
    m_neighbors.emplace_back(neighbor, distance);
}

bool GraphNode::findNeighbor(GraphNode* node) const{
    for(auto neighbor : m_neighbors)
        if (neighbor.first == node)
            return true;
    
    return false;
}

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>
#include <utility>
#include <initializer_list>
#include <string>

class GraphNode{
private:
    bool m_visited{};
    std::string m_name{};
    std::vector<std::pair<GraphNode*, int>> m_neighbors{};
    
public:
    GraphNode(){}
    GraphNode(const char* name):m_name{name}{}
    GraphNode(const char* name, std::initializer_list<std::pair<GraphNode*, int>> neighbors);
    void addNeighbor(GraphNode* neighbor, int distance);
    bool findNeighbor(GraphNode* node) const;
};

#endif
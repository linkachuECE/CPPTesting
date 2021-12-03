#ifndef GRAPH_H
#define GRAPH_H

#include "graphNode.h"
#include <vector>
#include <initializer_list>
#include <utility>

class Graph{
private:
    std::vector<GraphNode*> m_nodes{};

public:
    Graph(){}
    ~Graph(){for (auto node: m_nodes) delete node;}

    void addNode(const char* name);
    void addNode(const char* name, std::initializer_list<std::pair<const char*, double>> info);

    double findShortestDistance(const char* node1, const char* node2);

    void clearNodes();
};

#endif
#ifndef GRAPH_H
#define GRAPH_H

#include "graphVertex.h"
#include <vector>
#include <initializer_list>
#include <utility>

class Graph{
private:
    std::vector<GraphVertex*> m_nodes{};

public:
    Graph(){}
    ~Graph(){for (auto node: m_nodes) delete node;}

    void addVertex(const char* name);
    void addVertex(const char* name, std::initializer_list<std::pair<const char*, double>> info);

    GraphVertex* prepareNodes(const char* node1, const char* node2);
    double getShortestDistance(const char* node1, const char* node2);
    std::string getShortestPath(const char* node1, const char* node2);

    void resetNodes();
};

#endif
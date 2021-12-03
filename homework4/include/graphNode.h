#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>
#include <utility>
#include <initializer_list>
#include <string>
#include <limits>

class GraphNode{
private:
    std::string m_name{};
    std::vector<std::pair<GraphNode*, double>> m_neighbors{};
    bool m_visited{};
    double m_distanceFromSource{std::numeric_limits<double>::infinity()};
    GraphNode* m_predecessor{};
    
public:
    GraphNode(){}
    GraphNode(const char* name):m_name{name}{}
    GraphNode(const char* name, std::initializer_list<std::pair<GraphNode*, double>> neighbors);
    
    void addNeighbor(GraphNode* neighbor, double distance);
    bool findNeighbor(GraphNode* node) const;

    void visit();
    void setDistance(double distance);
    void setPredecessor(GraphNode* pred);

    std::string getName() const{return m_name;}
    GraphNode* getPredecessor() const{return m_predecessor;}
    double getDistance() const{return m_distanceFromSource;}
    bool getVisitStatus() const{return m_visited;}
};

#endif
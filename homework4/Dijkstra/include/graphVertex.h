#ifndef GRAPHVERTEX_H
#define GRAPHVERTEX_H

#include <vector>
#include <utility>
#include <initializer_list>
#include <string>
#include <limits>

class GraphVertex{
private:
    std::string m_name{};
    std::vector<std::pair<GraphVertex*, double>> m_neighbors{};
    bool m_visited{};
    double m_distanceFromSource{std::numeric_limits<double>::infinity()};
    GraphVertex* m_predecessor{};
    
public:
    GraphVertex(){}
    GraphVertex(const char* name):m_name{name}{}
    GraphVertex(const char* name, std::initializer_list<std::pair<GraphVertex*, double>> neighbors);
    
    void addNeighbor(GraphVertex* neighbor, double distance);
    bool findNeighbor(GraphVertex* node) const;

    void visit();
    void setDistance(double distance);
    void setPredecessor(GraphVertex* pred);

    std::string getName() const{return m_name;}
    GraphVertex* getPredecessor() const{return m_predecessor;}
    double getDistance() const{return m_distanceFromSource;}
    bool getVisitStatus() const{return m_visited;}
};

#endif
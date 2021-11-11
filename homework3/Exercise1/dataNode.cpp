#include "dataNode.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const DataNode& node){
    out << node.m_x << "," << node.m_y << ": " << node.m_data;
    return out;
}
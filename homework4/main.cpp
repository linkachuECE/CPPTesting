#include "graphNode.h"

int main(){
    GraphNode u{"U"};
    GraphNode x{"X", {{&u, 5}}};
    GraphNode w{"W", {{&u, 3}, {&x, 4}}};
    GraphNode v{"V", {{&w, 3}}};
    GraphNode y{"Y", {{&v, 4}, {&w, 8}, {&x, 7}}};
    GraphNode z{"Z", {{&y, 2}, {&x, 9}}};

    return 0;
}
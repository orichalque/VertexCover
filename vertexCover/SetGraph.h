/* 
 * File:   SetGraph.h
 * Author: E104607D
 *
 * Created on 9 mars 2016, 09:41
 */

#ifndef SETGRAPH_H
#define	SETGRAPH_H
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include "Graph.h"
using namespace std;

/**
 * @class SetGraph
 * @brief define a data structure for graphs, using a simple list
 * Position in the list -> Node A, value at the position -> B
 */
class SetGraph : Graph {
public:
    SetGraph();  
    
    SetGraph(int edges, int nodes) :
    Graph(edges, nodes) {
        AdjList = new node[nodes];
    }

    void generateEdges();
    
    void drawGraph();
    
    SetGraph(const SetGraph& orig);
    virtual ~SetGraph();
                
private:
    node* AdjList;  
    
    
};

#endif	/* SETGRAPH_H */


/* 
 * File:   Graph.h
 * Author: E104607D
 *
 * Created on 9 mars 2016, 09:40
 */

#ifndef GRAPH_H
#define	GRAPH_H
#include<vector>
/**
 * @class Graph
 * @brief abstract class for the 2 graph definitions
 */


struct node {
    int num;
    std::vector<int> adjacentNodes;
};

class Graph {
public:
    Graph();
    Graph(int edges, int nodes) :
    edges(edges), nodes(nodes) {
    }

    Graph(const Graph& orig);
    virtual ~Graph() = 0;
    
    void generateEdges();
    
    void SetEdges(int edges);
    int GetEdges() const;
    void SetNodes(int nodes);
    int GetNodes() const;    
    
    //void storeGraph(Graph g);
    void addVertex(node n);
    void addEdge(node a, node b);
    void removeVertex(node n);
    void removeEdge(node a, node b);
    
    void query(node a, node b); //are vertices x and y adjacent?

protected:
    int nodes; //Number of nodes
    int edges; //Number of edges
};

#endif	/* GRAPH_H */


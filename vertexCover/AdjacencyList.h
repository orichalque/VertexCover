/* 
 * File:   AdjacencyList.h
 * Author: E104607D
 *
 * Created on 23 mars 2016, 09:34
 */

#ifndef ADJACENCYLIST_H
#define	ADJACENCYLIST_H

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include "VertexCoverAbstractStruct.h"

struct Vertex{
    int num;
    std::vector< Vertex* > adjacentVertex;
};

struct Edge{
    int debut;
    int fin;
};

class AdjacencyList : public VertexCoverAbstractStruct {
public:
    /**
     * @brief Constructor empty
     */
    AdjacencyList();
    
    /**
     * @brief Copy constructor, not used
     * @param orig
     */
    AdjacencyList(const AdjacencyList& orig);
    
    /**
     * brief Constructor of graph, create the vertex from 0 to size -1 
     * @param size the number of vertex
     * 
     */
    AdjacencyList(int size);
    
    ~AdjacencyList();
    
    /**
     * @brief Display the graph as : Vertex ---> its adjacent vertexes
     */
    void displayGraph();
    /**
     * @brief Add a Vertex
     * @param i the vertex number to add
     * @return true if succeed, false otherwise
     * @deprecated
     */
    bool insert(int i);
    /**
     * @brief Remove a vertex 
     * @param i the vertex index
     * @return true if succeed, false otherwise
     */
    bool remove(int i);
    
    /**
     * @brief Add an edge to the graph
     * @param e the edge to add
     * @return true if success, false if not
     */
    bool removeEdge(Edge e);
    bool removeEdge(int i, int j);
    
    bool createEdge(int i, int j);
    bool createEdge(Edge e);
    
    bool generateEdges(int numberOfEdges);
            
protected:        
    std::vector<Vertex> graph;
    std::vector<Edge> edges;

private:

};

#endif	/* ADJACENCYLIST_H */


/* 
 * File:   Graph.cpp
 * Author: E104607D
 * 
 * Created on 9 mars 2016, 09:40
 */

#include "Graph.h"

Graph::Graph() {
}

Graph::Graph(const Graph& orig) {
}

Graph::~Graph() {
}

void Graph::SetEdges(int edges) {
    this->edges = edges;
}

int Graph::GetEdges() const {
    return edges;
}

void Graph::SetNodes(int nodes) {
    this->nodes = nodes;
}

int Graph::GetNodes() const {
    return nodes;
}

void Graph::generateEdges() {

}

void Graph::addEdge(node a, node b) {}

void Graph::addVertex(node n) {}

void Graph::removeEdge(node a, node b) {}

void Graph::removeVertex(node n) {}

void Graph::query(node a, node b) { }

//void Graph::storeGraph(Graph g) { }

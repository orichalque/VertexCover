/* 
 * File:   AdjacencyList.cpp
 * Author: E104607D
 * 
 * Created on 23 mars 2016, 09:34
 */

#include "AdjacencyList.h"
using namespace std;

AdjacencyList::AdjacencyList() {
}

AdjacencyList::AdjacencyList(int size) {
    for (int i = 0; i < size; ++i) {
        Vertex v;
        v.num = i;
        graph.push_back(v);        
    }
}

AdjacencyList::AdjacencyList(const AdjacencyList& orig) {
}

AdjacencyList::~AdjacencyList() {   
    graph.clear();
    edges.clear();
}

void AdjacencyList::displayGraph() {
    cout << "Affichage du graph" << endl;
    for (auto it : graph){
        cout << it.num << " ----->: ";
        for (auto j : it.adjacentVertex) {
            cout << j -> num << " ";
        }
        cout << " " << endl;
    }
}

void AdjacencyList::displayEdges() {
    cout << "Affichage des arêtes" << endl;
    for (auto it : edges){
        cout << it.debut << " - " << it.fin << endl;
    }
}

bool AdjacencyList::remove(int i) {
    //Do not use
}

bool AdjacencyList::insert(int i) {
    //Do not use
}

bool AdjacencyList::createEdge(int i, int j) {
    if (i == j){
        return false;
    }
    graph.at(i).adjacentVertex.push_back(&(graph.at(j)));
    graph.at(j).adjacentVertex.push_back(&(graph.at(i)));
    Edge e;
    e.debut = i; e.fin = j;
    edges.push_back(e);
    return true;
}

bool AdjacencyList::createEdge(Edge e) {
    if (e.debut == e.fin){
        return false;
    }
    graph.at(e.debut).adjacentVertex.push_back(&(graph.at(e.fin)));
    graph.at(e.fin).adjacentVertex.push_back(&(graph.at(e.debut)));
    edges.push_back(e);
    return true;
}

bool AdjacencyList::removeEdge(Edge e) {
    //Supression dans le sens ---->    
    auto result1 = find(graph.at(e.debut).adjacentVertex.begin(), graph.at(e.debut).adjacentVertex.end(), &graph.at(e.fin));
    if (result1 != graph.at(e.debut).adjacentVertex.end()){
        cout << "Found!" << endl;
        graph.at(e.debut).adjacentVertex.erase(result1);
    } else {
        return false;
    }
    //Supression dans le sens <----
    result1 = find(graph.at(e.fin).adjacentVertex.begin(), graph.at(e.fin).adjacentVertex.end(), &graph.at(e.debut));
        if (result1 != graph.at(e.fin).adjacentVertex.end()){
        cout << "Found!" << endl;
        graph.at(e.fin).adjacentVertex.erase(result1);
    } else {
        return false;
    }
    
    return true;
}

bool AdjacencyList::removeEdge(int i, int j) {
    //Supression  ---->    
    auto result1 = find(graph.at(i).adjacentVertex.begin(), graph.at(i).adjacentVertex.end(), &graph.at(j));
    if (result1 != graph.at(i).adjacentVertex.end()){
        cout << "Found!" << endl;
        graph.at(i).adjacentVertex.erase(result1);
    } else {
        return false;
    }
    //Supression <----
    result1 = find(graph.at(j).adjacentVertex.begin(), graph.at(j).adjacentVertex.end(), &graph.at(i));
        if (result1 != graph.at(j).adjacentVertex.end()){
        cout << "Found!" << endl;
        graph.at(j).adjacentVertex.erase(result1);
    } else {
        return false;
    }
    
    return true;
}

std::vector<Edge>* AdjacencyList::getEdges() {
    return &edges;
}

bool AdjacencyList::generateEdges(int numberOfEdges) {
    //Max of edge=n*(n-1)/2
    int n = graph.size();
    //If the numberOfEdges wanted is greater than the maximal, we still generate the max
    if (numberOfEdges > (n*(n-1)/2)){
        numberOfEdges = n*(n-1)/2 ;
    }
    
    vector<int> availableDestinations; 
    vector<int> availableStart; 
    for (auto it: graph){
        availableStart.push_back(it.num);
    }
    
    int initialNode; //Starting node of the edge
    int destinationNode; //Finishing node of the edge 
    
    
    random_device r;
    std::default_random_engine e1(r());
    uniform_int_distribution<int>* uid;
       
    //Each iteration add an edge
    //Bad Complexity : (-)(numberOfEdges * V * E)
    uid = new uniform_int_distribution<int>(0, graph.size()-1);
    initialNode = uid->operator ()(e1); //Randomly choose a starting node
    int i = 0;
    while (i < numberOfEdges && availableStart.size()>0){
        //Creation of the possible destination vector
        if (availableDestinations.size()>0)
            availableDestinations.clear();
        
        for (auto&& it : graph){
            if ((it.num != graph.at(availableStart.at(initialNode)).num) &&
                   (find(graph.at(availableStart.at(initialNode)).adjacentVertex.begin(), 
                            graph.at(availableStart.at(initialNode)).adjacentVertex.end(),
                            &it) == graph.at(availableStart.at(initialNode)).adjacentVertex.end())){
            
                //Removing the vertex and all its existiong edges from the destination possible vertex
                availableDestinations.push_back(it.num);      
            }                                               
        }
        
        uid = new uniform_int_distribution<int>(0, availableDestinations.size()-1);
        destinationNode = uid->operator ()(e1);

        

        //createEdge(graph.at(availableStart.at(initialNode)).num, availableDestinations.at(destinationNode));
        createEdge(graph.at(availableStart.at(initialNode)).num, graph.at(availableDestinations.at(destinationNode)).num);
        displayGraph();
        
        if (graph.at(availableStart.at(initialNode)).adjacentVertex.size() >= graph.size()-1){
            //The vertex cant have other edges, so we take it out of the available starts
            availableStart.erase(
                    find(availableStart.begin(), availableStart.end(), graph.at(availableStart.at(initialNode)).num));
        }
        
        if (graph.at(availableDestinations.at(destinationNode)).adjacentVertex.size() >= graph.size()-1){
            //The vertex cant have other edges, so we take it out of the available starts
            availableStart.erase(
                    find(availableStart.begin(), availableStart.end(), graph.at(availableDestinations.at(destinationNode)).num));
        }
        
        cout << "availableStart: " ;
        for (auto i : availableStart){
            cout << " " << i << ":";
        }
        
        cout << endl;
        
        uid = new uniform_int_distribution<int>(0, availableStart.size()-1);
        initialNode = uid->operator ()(e1);
        cout << "Starting node: " << initialNode << endl;
        ++i;
    }
    
    delete uid;
    return true;
}







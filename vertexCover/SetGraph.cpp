/* 
 * File:   SetGraph.cpp
 * Author: E104607D
 * 
 * Created on 9 mars 2016, 09:41
 */

#include "SetGraph.h"

SetGraph::SetGraph() {
}

SetGraph::SetGraph(const SetGraph& orig) {
}

SetGraph::~SetGraph() {
}

void SetGraph::generateEdges(){
    
    vector<int> nodeToChoose; //List of nodes that can be chosen for the edge
    for (int i = 0; i < edges; ++i){
        nodeToChoose.push_back(i);
    }
    
    vector<int> nodeOff; //List of Nodes that cannot be chosen for the edge
    
    int currentEdges(0);
    random_device rand;
    mt19937 gen(rand());
    
    int currentNode;
    
    uniform_int_distribution<> dis(0, this->nodes -1);    
    
    while (currentEdges < this -> edges){
        //Choose a node for 0 to n
        currentNode = dis(gen);
        
        
        //We add in nodeOff the current node, and all its adjacent nodes
        nodeOff.push_back(AdjList[currentNode].num);
        nodeOff.insert(nodeOff.end(), AdjList[currentNode].adjacentNodes.begin(), AdjList[currentNode].adjacentNodes.end());
        
        //We substract those node to the autorized node;
        for (auto val : nodeOff){
            nodeToChoose.erase(find(nodeToChoose.begin(), nodeToChoose.end(),  val));
        }
        
        uniform_int_distribution<> dis2(0, nodeToChoose.size() -1);
        
        AdjList[currentNode].adjacentNodes.push_back(dis2(gen));
        
        currentEdges ++;
    }
}

void SetGraph::drawGraph() {
    for (int i = 0; i < nodes; ++i){
        cout << i << " : ";
        for (auto val:AdjList[i].adjacentNodes){
            cout << val;
        }
        cout << endl;
    }
}
/* 
 * File:   GreedyVC.cpp
 * Author: E104607D
 * 
 * Created on 29 mars 2016, 13:13
 */

#include "GreedyVC.h"
using namespace std;

GreedyVC::GreedyVC() {
}

GreedyVC::GreedyVC(const GreedyVC& orig) {
}

GreedyVC::~GreedyVC() {
}

std::vector<Vertex*> GreedyVC::calculate(AdjacencyList& graph) {
    vector<Vertex*> VC;
    cout << "Step 1" << endl;
    vector<Edge> E; //copy graphe edges;
    
    
    for (auto it = graph.getEdges() -> begin(); it != graph.getEdges()->end(); it++){
        Edge edgeToCopy;
        edgeToCopy.debut = it -> debut;
        edgeToCopy.fin = it -> fin;
        E.push_back(edgeToCopy);
    }
    
    vector<Edge> E2;
    
    random_device r;
    std::default_random_engine e1(r());
    uniform_int_distribution<int>* uid;
    Edge currentEdge;
    cout << "Step 2: debut de la boucle" << endl;
    
    while (!E.empty()){
        //Choix de l'arete a ajouter
        uid = new uniform_int_distribution<int>(0, E.size()-1);
        int pos = uid -> operator ()(e1);
        currentEdge = E.at(pos);
        
        
        cout << "Edge: " << currentEdge.debut << " - " << currentEdge.fin << endl;
        //Ajout des deux vertex de l'arete au VC
        VC.push_back(&graph.getGraph().at(currentEdge.debut));
        VC.push_back(&graph.getGraph().at(currentEdge.fin));
        
        cout << "Step 3 : Vertex adjacent a u" << endl;
        
        for (int i = 0; i < graph.getGraph()[currentEdge.debut].adjacentVertex.size(); ++i){
            Edge edgeCovered;
            edgeCovered.debut = currentEdge.debut;
            edgeCovered.fin = graph.getGraph()[currentEdge.debut].adjacentVertex[i]->num;
            if (! (edgeCovered == currentEdge)){
                E2.push_back(edgeCovered);
            }    
        }
        
        cout << "Step 4 : Vertex adjacent a v" << endl;
        for (int i = 0; i < graph.getGraph()[currentEdge.fin].adjacentVertex.size(); ++i){
            Edge edgeCovered;
            edgeCovered.debut = currentEdge.fin;
            edgeCovered.fin = graph.getGraph()[currentEdge.fin].adjacentVertex[i]->num;
            if (! (edgeCovered == currentEdge)){
                E2.push_back(edgeCovered);
            }    
        }
        
        E.erase(E.begin()+pos);
        
        cout << "Step 5 : Suppression de E' " << endl;
        for (auto edgeToRemove : E2){
            auto it = find(E.begin(), E.end(), edgeToRemove);
            if (it != E.end()){
                E.erase(it);
            }
        }
        
        E2.clear();               
        
        //pick edges in E
        //V' += E.vertex
        //E' = Aretes incidentes au vertex de E
        //E -= E'
    }
    
    for (auto v : VC){
        cout << v->num << " ";        
    }
    cout << endl;
    return VC;
    
}



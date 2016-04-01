/* 
 * File:   AVC.cpp
 * Author: E104607D
 * 
 * Created on 1 avril 2016, 12:56
 */

#include "AVC.h"
using namespace std;

AVC::AVC() {
}

AVC::AVC(const AVC& orig) {
}

AVC::~AVC() {
}

//Faire un autre avec un K a décrémenter à chaque appel recursif;
std::vector<Vertex*> AVC::calculate(AdjacencyList& graph) {
    vector<int>* vertexCover;
    vector<Vertex*> vc;
    vector<int> vertexDeleted;
    calculateRec(graph, vertexCover, vertexDeleted);
    if (vertexCover != NULL){
        cout << "Vertex cover de taille: " << vertexCover->size() << endl;
        for (auto i : *vertexCover){
            //Copie des adresses des vertex dans le vector
            vc.push_back(&graph.getGraph().at(i));
        }
        return vc;
    } else {
        return NULL;
    }
}

bool AVC::calculateRec(AdjacencyList& graph, std::vector<int>* vertexCover, std::vector<int> deleted) {
    if (vertexCover != NULL){
        return false;
    }
    if (graph.getEdges()->empty()){
        vertexCover = &deleted;
        return true;
    }
    
    random_device r;
    std::default_random_engine e1(r());
    uniform_int_distribution<int>* uid;
    uid = new uniform_int_distribution<int>(0, graph.getEdges()->size());
    Edge e = graph.getEdges()->at(uid -> operator ()(e1));
    
    //Choisir arete aléatoire
    //Construire graphe G1 sans le vertex u, et graphe G2 sans le vertex v
    //return fonction sur G1 v G2
    
}


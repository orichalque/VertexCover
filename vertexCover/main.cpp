/* 
 * File:   main.cpp
 * Author: E104607D
 *
 * Created on 23 mars 2016, 09:34
 */

#include <cstdlib>

#include "VertexCoverAbstractStruct.h"
#include "AdjacencyList.h"
#include "VertexCoverAbstract.h"
#include "GreedyVC.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int sz = 35;
    AdjacencyList* v = new AdjacencyList(sz);
    v->displayGraph();
    v->generateEdges(85);
    v->displayGraph();
    
    VertexCoverAbstract* vc = new GreedyVC();
    
    cout << "START " << endl;
    vc->calculate(*v);
    
    return 0;
}


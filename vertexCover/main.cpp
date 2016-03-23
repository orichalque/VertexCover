/* 
 * File:   main.cpp
 * Author: E104607D
 *
 * Created on 23 mars 2016, 09:34
 */

#include <cstdlib>

#include "VertexCoverAbstractStruct.h"
#include "AdjacencyList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int sz = 5;
    VertexCoverAbstractStruct* v = new AdjacencyList(sz);
    v->displayGraph();
    v->generateEdges(50);
    v->displayGraph();
    return 0;
}


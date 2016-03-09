/* 
 * File:   main.cpp
 * Author: E104607D
 *
 * Created on 9 mars 2016, 09:33
 */

#include <cstdlib>
#include "SetGraph.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    SetGraph *g = new SetGraph(5, 5);
    g -> generateEdges();
    g -> drawGraph();
    return 0;
}


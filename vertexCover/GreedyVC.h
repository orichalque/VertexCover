/* 
 * File:   GreedyVC.h
 * Author: E104607D
 *
 * Created on 29 mars 2016, 13:13
 */

#ifndef GREEDYVC_H
#define	GREEDYVC_H

#include <vector>
#include "VertexCoverAbstract.h"


class GreedyVC : public VertexCoverAbstract {
public:
    GreedyVC();
    GreedyVC(const GreedyVC& orig);
    ~GreedyVC();

    std::vector<Vertex*> calculate(AdjacencyList& graph);

private:

};

#endif	/* GREEDYVC_H */


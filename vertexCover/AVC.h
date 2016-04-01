/* 
 * File:   AVC.h
 * Author: E104607D
 *
 * Created on 1 avril 2016, 12:56
 */

#ifndef AVC_H
#define	AVC_H

#include "AdjacencyList.h"


class AVC : public VertexCoverAbstract{
public:
    AVC();
    AVC(const AVC& orig);
    virtual ~AVC();
    
    std::vector<Vertex*> calculate(AdjacencyList& graph);
    bool calculateRec(AdjacencyList& graph, std::vector<int>* vertexCover, std::vector<int> deleted);
private:
    
};

#endif	/* AVC_H */


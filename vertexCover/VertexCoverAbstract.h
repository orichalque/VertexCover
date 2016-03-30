/* 
 * File:   VertexCoverAbstract.h
 * Author: E104607D
 *
 * Created on 29 mars 2016, 12:57
 */

#ifndef VERTEXCOVERABSTRACT_H
#define	VERTEXCOVERABSTRACT_H
#include "VertexCoverAbstractStruct.h"
#include "AdjacencyList.h"

class VertexCoverAbstract {
public:
    VertexCoverAbstract();
    VertexCoverAbstract(const VertexCoverAbstract& orig);
    virtual ~VertexCoverAbstract();
    
    virtual std::vector<Vertex*> calculate(AdjacencyList& graph) = 0;
    
private:

};

#endif	/* VERTEXCOVERABSTRACT_H */


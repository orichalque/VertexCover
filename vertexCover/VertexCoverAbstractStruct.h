/* 
 * File:   VertexCoverAbstractStruct.h
 * Author: E104607D
 *
 * Created on 23 mars 2016, 09:34
 */

#ifndef VERTEXCOVERABSTRACTSTRUCT_H
#define	VERTEXCOVERABSTRACTSTRUCT_H

class VertexCoverAbstractStruct {
public:
    VertexCoverAbstractStruct();
    VertexCoverAbstractStruct(const VertexCoverAbstractStruct& orig);
    virtual ~VertexCoverAbstractStruct();
    virtual bool insert(int i)=0;
    virtual bool remove(int i)=0;
    virtual bool createEdge(int i, int j)=0;
    virtual void displayGraph() = 0;
    virtual bool removeEdge(int i, int j) = 0;
    virtual bool generateEdges(int numberOfEdges) = 0;
private:

};

#endif	/* VERTEXCOVERABSTRACTSTRUCT_H */


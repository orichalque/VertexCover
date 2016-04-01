/* 
 * File:   VertexCoverAbstractStruct.h
 * Author: E104607D
 *
 * Created on 23 mars 2016, 09:34
 */

#ifndef VERTEXCOVERABSTRACTSTRUCT_H
#define	VERTEXCOVERABSTRACTSTRUCT_H
#include <vector>

struct Edge{
    int debut;
    int fin;
    
    bool operator==(Edge e) const{
        if ((e.debut == debut && e.fin == fin) || (e.debut == fin && e.fin == debut)){
            return true;
        } else {
            return false;
        }
    }
    
    Edge& operator=(const Edge& right) {
        // Check for self-assignment!
        if (this == &right) // Same object?
            return *this; // Yes, so skip assignment, and just return *this.
        
        debut = right.debut;
        fin = right.fin;
        return *this;
    }

    
};

struct Vertex{
    int num;
    std::vector< Vertex* > adjacentVertex;
};

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
    
//    virtual std::vector<Edge> getEdges() = 0;

protected:    
    std::vector<Edge> edges;
};

#endif	/* VERTEXCOVERABSTRACTSTRUCT_H */


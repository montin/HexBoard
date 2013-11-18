/* 
 * File:   Edge.h
 * Author: loris
 *
 * Created on November 17, 2013, 5:02 PM
 */

#ifndef _EDGE_H
#define	_EDGE_H
#include "Graph.h"
class Vertex;
class Edge {
public:
    Edge();
    Edge(Vertex * pVertex);
    //Edge(const Edge& orig);
    virtual ~Edge();
    inline Vertex * getVertex(){return pVertex;};
    inline double  getCost(){return cost;};
private:
    Vertex * pVertex;
    double cost;
};

#endif	/* _EDGE_H */


/* 
 * File:   Vertex.h
 * Author: loris
 *
 * Created on November 17, 2013, 4:58 PM
 */
#ifndef _VERTEX_H
#define	_VERTEX_H
#include "Graph.h"
using namespace std;
typedef pair <int,int> Coordinate;
class Edge;
typedef vector<Edge *> EdgeVector;



class Vertex {
private:
    Coordinate coordinate;
    int player;
    double calcCost;
    vector<pair<int,int> > getEdgesCoordinates(Vertex* pVertex);
    bool topLeftCorner(Vertex* pVertex);
    bool topRightCorner(Vertex* pVertex);
    bool bottomRightCorner(Vertex* pVertex);
    bool bottomLeftCorner(Vertex* pVertex);
public:
    EdgeVector edges;
    Vertex* prevVertex;
    Vertex();
    Vertex(Coordinate coordinate);
    virtual ~Vertex();
    inline Coordinate getCoordinate(){return this->coordinate;};
    void addEdge(Vertex* pVertex);
    void engage(int player);
    inline int getPLayer(){return player;}
    inline void setCalcCost(double calcCost){this->calcCost=calcCost;}
    inline double getCalcCost(){return this->calcCost;}

};

#endif	/* _VERTEX_H */


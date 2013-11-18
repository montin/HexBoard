/* 
 * File:   Graph.h
 * Author: loris
 *
 * Created on November 17, 2013, 2:50 PM
 */

#ifndef _GRAPH_H
#define	_GRAPH_H





#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <limits>
#include <algorithm>
#include <cmath>
#include <exception>


#include "Vertex.h"
#include "Edge.h"
using namespace std;
class Vertex;


const int EMPTYFIELD=0;
const int PLAYER1=1;
const int PLAYER2=2;

typedef vector<Vertex *> VertexVector;
typedef VertexVector::iterator VertexVectorIter;

typedef vector<Edge*>::iterator EdgeVectorIter;

typedef pair<int,int> Coordinate;


// helper overload function to compare coordinates
inline bool operator==(const Coordinate& lhs, const Coordinate& rhs){ return lhs.first==rhs.first && lhs.second ==rhs.second; }
inline bool operator!=(const Coordinate& lhs, const Coordinate& rhs){ return !(lhs==rhs); }
ostream & operator<<(ostream & leftOp, Vertex * rightOp);


class Graph {
private:
    int size;

bool northWestCorner(Vertex* pVertex);
bool northEastCorner(Vertex* pVertex);
bool southEastCorner(Vertex* pVertex);
bool southWestCorner(Vertex* pVertex);
bool westEdge(Vertex* pVertex);
bool eastEdge(Vertex* pVertex);
bool northEdge(Vertex* pVertex);
bool southEdge(Vertex* pVertex);
bool innerVertex(Vertex* pVertex);
void doCalcStep(Vertex * pv,int player);

bool legal(Coordinate coord);

vector<pair<int,int> > getEdgesCoordinates(Vertex *pVertex);
public:
    VertexVector vertexes;
    VertexVector vertexesUsed;

    Graph();
    Graph(int size);

    ~Graph();

    /*
     * add vertex for given Coordinate
     */
    Vertex* addVertex(Coordinate coord);

    /*get Vertex object by it's coordinate
     *
     */
    Vertex * getVertexByCoordinate(Coordinate coord);

    VertexVector *getAjacentVertexes(Coordinate coord);

    bool addStep(int player,Coordinate coord);


    /*
     * adding edge to specified vertex
     */

    /*
     * compute all paths from source to other vertexes
     */
    Vertex* computeNextStep(Vertex *Vertex);


    /*
     * getting shortest path for selected target
     *
     */

    void fillGraph();

    /*
     * print detailed info on graph (vertexes and edges)
     *
     */
    void print();
    void printBoard();

    inline int getSize() {return this->size;}

    //printing vector with shortest path
    void reset();
    void computePaths(Vertex* pMainVertex,int player);
    VertexVector getShortestPath (Vertex * pSourceVertex,Vertex * pTargetVertex);
    bool gameOver(int player);
    bool isWestSide(Vertex* v);
    bool isEastSide(Vertex* v);
    bool isNorthSide(Vertex* v);
    bool isSouthSide(Vertex* v);


};

#endif	/* _GRAPH_H */
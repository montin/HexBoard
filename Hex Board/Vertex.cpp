/* 
 * File:   Vertex.cpp
 * Author: loris
 * 
 * Created on November 17, 2013, 4:58 PM
 */

#include "Vertex.h"

Vertex::Vertex():coordinate(0,0),player(EMPTYFIELD) {
}

Vertex::Vertex(Coordinate coordinate):coordinate(coordinate),player(EMPTYFIELD) {

}

//Vertex::Vertex(const Vertex& orig) {
//}

Vertex::~Vertex() {
}
void Vertex::addEdge(Vertex* pVertex){
    Edge* pEdge=new Edge(pVertex);
    edges.push_back(pEdge);
}
void Vertex::engage(int player){
    this->player=player;
}







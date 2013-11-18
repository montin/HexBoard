#include "Graph.h"
#include "Vertex.h"

//constructors
ostream & operator<<(ostream & leftOp, Vertex * rightOp)
 {
    Coordinate coord=rightOp->getCoordinate();
    string playerCaption="Empty";
    if(rightOp->getPLayer()==PLAYER1) playerCaption="Player 1";
    if(rightOp->getPLayer()==PLAYER2) playerCaption="Player 2";

    leftOp << "Coordinate [x:" << coord.first << ", y:" <<coord.second  << "],"<< playerCaption<<endl;
    leftOp << "Coordinate [x:" << coord.first << ", y:" <<coord.second  << "]"<<endl;
    for (EdgeVector::iterator iter = rightOp->edges.begin(); iter != rightOp->edges.end(); iter++) {
        Vertex* pAdjVertex=(*iter)->getVertex();
        leftOp << "\tedge to [x: "<<pAdjVertex->getCoordinate().first <<", y:"<< pAdjVertex->getCoordinate().second << "]"<<endl ;
    }
    return leftOp;
}

Graph::Graph() : size(7) {

}

Graph::Graph(int size) : size(size) {

}
//destructor

Graph::~Graph() {
}

VertexVector * Graph::getAjacentVertexes(Coordinate coord) {
    return 0;
}
bool Graph::legal(Coordinate coord){
    return  !(coord.first < 1 || coord.first > size || coord.second <1 || coord.second > size);

}


bool Graph::addStep(int player,Coordinate coord) {
    if(!this->legal(coord)) return false;
    Vertex* pVertex=this->getVertexByCoordinate(coord);
    if(pVertex->getPLayer()!=EMPTYFIELD) return false;
    pVertex->engage(player);
    return true;
}

///fill Hex Board with size of graph
Vertex* Graph::addVertex(Coordinate coord) {
    vertexes.push_back(new Vertex(coord));
    //cout << "x " << coord.first << " y " << coord.second << endl;
}

void Graph::fillGraph() {
    for (int i = 1; i <= this->size; i++) {
        for (int j = 1; j<= this->size; j++) {
            Coordinate coord(i, j);
            this->addVertex(coord);
        }
    }
    for (VertexVectorIter vertex_iter = vertexes.begin(); vertex_iter != vertexes.end(); vertex_iter++) {
        Vertex* pMainVertex=*vertex_iter;
        vector<pair<int,int> > coordinateSet=this->getEdgesCoordinates(pMainVertex);
        for(vector<pair<int,int> >::iterator iter=coordinateSet.begin();iter !=coordinateSet.end();iter++){
            Vertex* pVertex=this->getVertexByCoordinate((Coordinate)(*iter));
            pMainVertex->addEdge(pVertex);

        }
    }
}

Vertex* Graph::getVertexByCoordinate(Coordinate coordinate){
    int index=(coordinate.first-1)*size +coordinate.second-1;
    return vertexes[index];
}

vector<pair<int,int> > Graph::getEdgesCoordinates(Vertex *pVertex){
    vector<pair<int,int> > retSet;
    Coordinate mainCoord =pVertex->getCoordinate();
    if(this->northWestCorner(pVertex)){
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second+1));
    }
    if(this->northEastCorner(pVertex)){
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second+1));
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second+1));
    }
    if(this->southEastCorner(pVertex)){
          //pair<int,int> coord(mainCoord.first-1,mainCoord.second);
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second));
          //pair<int,int> coord(mainCoord.first,mainCoord.second-1);
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second-1));
    }
    if(this->southWestCorner(pVertex)){
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second-1));
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second-1));
    }
    if(this->westEdge(pVertex)){
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second-1));
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second+1));
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second+1));
    }
    if(this->eastEdge(pVertex)){
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second-1));
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second+1));
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second+1));
    }
    if(this->northEdge(pVertex)){
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second+1));
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second+1));
    }
    if(this->southEdge(pVertex)){
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second));

          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second-1));
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second-1));
    }
    if(this->innerVertex(pVertex)){
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second));
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second));

          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second-1));
          retSet.push_back(pair<int,int>(mainCoord.first,mainCoord.second+1));
         
          retSet.push_back(pair<int,int>(mainCoord.first+1,mainCoord.second-1));                    
          retSet.push_back(pair<int,int>(mainCoord.first-1,mainCoord.second+1));                              
          
    }
    return retSet;
}
//Print Board fro current status

void Graph::print() {
        for (VertexVectorIter vertex_iter = vertexes.begin(); vertex_iter != vertexes.end(); vertex_iter++) {
            cout << (*vertex_iter);
        }

}

void Graph::printBoard() {
    Coordinate coord1(5, 5);
    Coordinate coord2(6, 6);
    for(int x=1;x<=this->size;x++){
        cout << "  " << x;
    }
    cout <<endl;
    for(int y=1;y<=this->size;y++){
        cout << string( y, ' ' ) << y;
        for(int x=1;x<=this->size;x++){
            Coordinate c(x, y);
            Vertex * v=this->getVertexByCoordinate(c);
            if(v->getPLayer()!=EMPTYFIELD){
                if(v->getPLayer()==PLAYER1){
                    cout << "  x";
                }
                else{
                        cout << "  0";
                }
            }
            else{
                cout << "  .";
            }

        }
        cout << " "<< y << endl;
    }
}

bool Graph::northWestCorner(Vertex* pVertex){ //northWestCorner
    return (pVertex->getCoordinate().first==1 && pVertex->getCoordinate().second==1);
}
bool Graph::northEastCorner(Vertex* pVertex){//northEastCorner
    return (pVertex->getCoordinate().first==7 && pVertex->getCoordinate().second==1);
}

bool Graph::southEastCorner(Vertex* pVertex){ //southEastCorner
    return (pVertex->getCoordinate().first==size && pVertex->getCoordinate().second==size);
}
bool Graph::southWestCorner(Vertex* pVertex){//southWestCorner
    return (pVertex->getCoordinate().first==1 && pVertex->getCoordinate().second==size);
}

bool Graph::northEdge(Vertex* pVertex){//southWestCorner
    return (pVertex->getCoordinate().first>1 && pVertex->getCoordinate().first <size && pVertex->getCoordinate().second==1);
}
bool Graph::southEdge(Vertex* pVertex){//southWestCorner
    return (pVertex->getCoordinate().first>1 && pVertex->getCoordinate().first <size && pVertex->getCoordinate().second==size);
}
bool Graph::westEdge(Vertex* pVertex){//southWestCorner
    return (pVertex->getCoordinate().first==1 && pVertex->getCoordinate().second >1 && pVertex->getCoordinate().second < size);
}

bool Graph::eastEdge(Vertex* pVertex){//southWestCorner
    return (pVertex->getCoordinate().first==size && pVertex->getCoordinate().second >1 && pVertex->getCoordinate().second < size);
}
bool Graph::innerVertex(Vertex* pVertex){
    return (pVertex->getCoordinate().first> 1 && pVertex->getCoordinate().first < size && pVertex->getCoordinate().second >1 && pVertex->getCoordinate().second < size);
}

void Graph::reset(){
    for (VertexVectorIter vertex_iter = vertexes.begin(); vertex_iter != vertexes.end(); vertex_iter++) {
        (*vertex_iter)->setCalcCost(numeric_limits<float>::infinity());
        (*vertex_iter)->prevVertex=0;
    }
    this->vertexesUsed.clear();

}

bool Graph::isWestSide(Vertex* v){
    return (v->getCoordinate().first==1);
}
bool Graph::isEastSide(Vertex* v){
    return (v->getCoordinate().first==size);
}
bool Graph::isNorthSide(Vertex* v){
    return (v->getCoordinate().second==1);
}
bool Graph::isSouthSide(Vertex* v){
    return (v->getCoordinate().second==size);
}

bool Graph::gameOver(int player){
    for(VertexVectorIter iter=vertexes.begin();iter!=vertexes.end() ;iter++){
        if((*iter)->getPLayer()!=player) continue;
        if(player==PLAYER1 && !isWestSide(*iter)) continue; 
        if(player==PLAYER2 && !isNorthSide(*iter)) continue;
        cout << (*iter) << endl;
        this->computePaths(*iter,player);
        for(VertexVectorIter iter1=vertexes.begin();iter1!=vertexes.end() ;iter1++){
            if((*iter)->getPLayer()!=player) continue;
            if(player==PLAYER1 && !isEastSide(*iter)) continue;
            if(player==PLAYER2 && !isSouthSide(*iter)) continue;
            VertexVector vv=   this->getShortestPath(*iter,*iter1);
            string comma = "";
            for(VertexVectorIter it=vv.begin();it!=vv.end() ;it++){
                cout << comma << "Coordinate[x:"<<(*it)->getCoordinate().first<<",y:"<<(*it)->getCoordinate().second<<"]"<<endl;
                comma = ",";
            }
            cout << endl << endl;
        }
       
    }
    return false;
    
}

void Graph::computePaths(Vertex* pMainVertex,int player) {
    this->reset();
    if(pMainVertex->getPLayer()!=player) return;
    pMainVertex->setCalcCost(0);
    this->doCalcStep(pMainVertex,player);
}

void Graph::doCalcStep(Vertex * pv,int player) {
    double sourceCost = pv->getCalcCost();

    Vertex* pMinVertex = 0;
    for (EdgeVectorIter edge_iter = pv->edges.begin(); edge_iter != pv->edges.end(); edge_iter++) {
        Edge * e = *edge_iter;
        Vertex* v = e->getVertex();
        if(v->getPLayer()!=player) continue;
        if (find(this->vertexesUsed.begin(), this->vertexesUsed.end(), v) != this->vertexesUsed.end())
            continue;
        float newCost = sourceCost + e->getCost();
        if (newCost < v->getCalcCost()) {
            v->setCalcCost(newCost);
            v->prevVertex = pv;
        }
        if (!pMinVertex || pMinVertex->getCalcCost() >= v->getCalcCost()) {
            pMinVertex = v;
        }
    }
    if (pMinVertex) {
        vertexesUsed.push_back(pv);
        this->doCalcStep(pMinVertex,player);
    }
}
VertexVector Graph::getShortestPath (Vertex * pSourceVertex,Vertex * pTargetVertex) {
        VertexVector retVector;
        Vertex * target = pTargetVertex;
        if(pTargetVertex->getCalcCost()==numeric_limits<float>::infinity()) return retVector;
        while (target) {
            retVector.insert(retVector.begin(), target);
            target = target->prevVertex;
        }
        return retVector;
    }




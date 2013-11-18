/* 
 * File:   main.cpp
 * Author: loris
 *
 * Created on November 17, 2013, 2:48 PM
 */

#include <stdlib.h>
#include "Graph.h"
#include <iostream>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {

    Graph* g= new Graph(7);
    g->fillGraph();

    int i=1;
    bool bTurn=true;
    do{
        int player=(bTurn)?PLAYER1:PLAYER2;
        string playerCaption=(bTurn)?"PLAYER1":"PLAYER2";
        int x;

        //cin >> x ;
        cout << "enter x coordinate for " << playerCaption << ": ";
        while ( !(cin >> x) )
        {
            cin.clear();
            cin.ignore();
            cout << "Incorrect entry. Try again "<< endl;
            cout << "enter x coordinate for " << playerCaption << ": ";
        }        

        int y;
        cout << "enter y coordinate for " << playerCaption << ": ";
        while ( !(cin >> y) )
        {
            cin.clear();
            cin.ignore();
            cout << "Incorrect entry. Try again "<< endl;
            cout << "enter y coordinate for " << playerCaption << ": ";
        }
        if(g->addStep(player,Coordinate(x,y))){
            g->printBoard();
            if(g->gameOver(player)) continue;
            bTurn=!bTurn;
            int player=(bTurn)?PLAYER1:PLAYER2;
        }


    }while(true);

    cout << "game over";

    

    return (EXIT_SUCCESS);
}


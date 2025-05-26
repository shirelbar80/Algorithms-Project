#include <iostream>
#include <stdlib.h>
#include "Graph1.h"
#include "Graph2.h"
using namespace std;

//Instructions for the program:
//enter the following parameters in this order: 
// size of large jug, size of small jug, size of large jug in the end of the program (small jug is 0), 
// which method would you like to use (1 or 2), if you would like to measure the time of solving the problem enter 1 if not then enter 0

int main() {
    int largeJug, smallJug, W, method, showTime;
    cin >> largeJug >> smallJug >> W >> method >> showTime;//get all details

    //check for invalid parameters
    if ((method != 1 && method != 2) || (smallJug >= largeJug) || (W > largeJug) || (smallJug < 0) || (largeJug < 0) || (W < 0) 
        || (showTime != 1 && showTime != 0)) {//all invalid inputs
        cout << "Invalid input." << endl;
        exit(1);
    }

    Graph* graph = nullptr;

    if (method == 1) {
        graph = new Graph1(smallJug, largeJug, (bool)showTime);
    }
    else if(method == 2){
        graph = new Graph2(smallJug, largeJug, (bool)showTime);
    }

    graph->solveWaterJug(smallJug, largeJug, W);//activates the relevant function depending on the method

    delete graph;

    return 0;
}


#include <iostream>
using namespace std;
#include "Utils.h"



int main() {
    int largeJug, smallJug, W, method, showTime;
    cin >> largeJug >> smallJug >> W >> method >> showTime;

    if ((method != 1 && method != 2) || (smallJug >= largeJug || W > largeJug) || (smallJug < 0 || largeJug < 0 || W < 0)) {//all invalid inputs
        cout << "Invalid input." << endl;
        return 1;
    }

    if (method == 1) {
        solveWaterJug1(largeJug, smallJug, W, showTime);
    }
    else {



    }

    return 0;
}


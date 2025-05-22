#include <iostream>
using namespace std;
#include "Utils.h"



int main() {
    int L, S, W, method, showTime;
    cin >> L >> S >> W >> method >> showTime;

    if (method != 1 && method != 2) {
        cout << "Invalid method. Only method 1 is implemented." << endl;
        return 1;
    }

    if (S >= L || W > L) {
        cout << "Invalid input" << endl;
        return 1;
    }
  

    solveWaterJug(L, S, W, showTime);

    return 0;
}


#pragma once
#include <iostream>
#include <chrono>
using namespace std;



void solveWaterJug1(int largeJug, int smallJug, int W, bool showTime);
string GetOperation(pair<int, int> from, pair<int, int> to, int smallJug, int largeJug);
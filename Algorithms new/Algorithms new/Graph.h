#pragma once
#include <map>
#include <list>
#include <utility>
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Graph {
    
    int smallJug;
    int largeJug;
    bool showTime;

protected: 
    string GetOperation(pair<int, int> from, pair<int, int> to, int smallJug, int largeJug);

public:

    Graph(int _smallJug, int _largeJug, bool _showTime) : smallJug(_smallJug), largeJug(_largeJug), showTime(_showTime) {}

    int getSmallJug() { return smallJug; }
    int getLargeJug() { return largeJug; }
    bool getShowTime() { return showTime; }

    list<pair<int, int>> CalculateAdjList(pair<int, int> u);
    virtual void AddEdge(pair<int, int> u, pair<int, int> v) = 0;
    virtual list<pair<int, int>> GetAdjList(pair<int, int> u) = 0;
    virtual void solveWaterJug(int smallJug, int largeJug, int W) = 0;


};

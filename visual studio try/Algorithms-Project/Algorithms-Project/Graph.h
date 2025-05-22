#pragma once
#include <map>
#include <list>
#include <utility>
#include <vector>
using namespace std;

class Graph {
private:
    map<pair<int, int>, list<pair<int, int>>> adjList; // graph representation
    // Each vertex is a pair of integers (small jug, large jug) 

public:
    void MakeEmptyGraph(int largeJug, int smallJug);
    void AddAllPossibleEdges(int largeJug, int smallJug);
    void AddEdge(pair<int, int> u, pair<int, int> v);
    list<pair<int, int>> GetAdjList(pair<int, int> u);
    map<pair<int, int>, vector<pair<int, int>>> BFS(pair<int, int> start);
};

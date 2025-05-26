#pragma once
#include "Graph.h"
#include <chrono>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;


class Graph2 : public Graph
{
private:
	map<pair<int, int>, list<pair<int, int>>> adjList; // graph representation

	pair<int, int> fromString(const string& s);

public:

	Graph2(int _smallJug, int _largeJug, bool _showTime) : Graph(_smallJug, _largeJug, _showTime) {}

	void solveWaterJug(int smallJug, int largeJug, int W) override;
	void AddEdge(pair<int, int> u, pair<int, int> v) override;
	list<pair<int, int>> GetAdjList(pair<int, int> u) override;
};
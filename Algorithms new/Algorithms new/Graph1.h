#pragma once
#include <list>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <chrono>
#include <iostream>
#include "Graph.h"

using namespace std;


class Graph1 : public Graph
{
private:
	vector < pair <pair <int, int>, list < pair <int, int>>>> adjList;// graph representation
	map<pair<int, int>, int> vertexToIndex;  //Maps (a,b) ? index in adjList

	map<pair<int, int>, vector<pair<int, int>>> BFS(pair<int, int> start, pair<int, int> goal);
	void addAllPossibleEdges();
	int findVertexIndex(const pair<int, int>& u);
	void MakeEmptyGraph(int n);
	void AddEdge(pair<int, int> u, pair<int, int> v) override;
	list<pair<int, int>> GetAdjList(pair<int, int> u) override;

public:

	Graph1(int _smallJug, int _largeJug, bool _showTime) : Graph(_smallJug, _largeJug, _showTime) {

		MakeEmptyGraph((_smallJug) * (_largeJug));//creates a graph with no edges
		addAllPossibleEdges();//adds all the possible edges to the graph
	}

	
	void solveWaterJug(int smallJug, int largeJug, int W) override;


};

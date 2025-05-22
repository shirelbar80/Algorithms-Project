#include "Graph.h"
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

void Graph::MakeEmptyGraph(int largeJug, int smallJug) {
    // Create all possible vertices from 0 to smallJug and 0 to largeJug, no edges
    for (int i = 0; i <= smallJug; i++) {
        for (int j = 0; j <= largeJug; j++) {
            pair<int, int> vertex = {i, j};
            adjList[vertex] = list<pair<int, int>>(); // No neighbors (no edges)
        }
    }
}

void Graph::AddAllPossibleEdges(int largeJug, int smallJug) {
    for (const auto& vertex : adjList) { // Iterate over all vertices
        int small = vertex.first.first;
        int large = vertex.first.second;
        pair<int, int> u = {small, large};

        // 1. Fill small jug
        AddEdge(u, {smallJug, large});

        // 2. Fill large jug
        AddEdge(u, {small, largeJug});

        // 3. Empty small jug
        AddEdge(u, {0, large});

        // 4. Empty large jug
        AddEdge(u, {small, 0});

        // 5. Pour small into large
        int pour = min(small, largeJug - large);
        AddEdge(u, {small - pour, large + pour});

        // 6. Pour large into small
        pour = min(large, smallJug - small);
        AddEdge(u, {small + pour, large - pour});
    }

    // Sort adjacency lists lexicographically
    for (auto& pair : adjList) {
        pair.second.sort(); // Ensure lexicographic order
    }
}

void Graph::AddEdge(pair<int, int> u, pair<int, int> v) {// Add an edge between vertices u and v
    adjList[u].push_back(v);
    adjList[u].sort();
}

list<pair<int, int>> Graph::GetAdjList(pair<int, int> u) {// Get the adjacency list of vertex u
    return adjList[u];
}

// Perform BFS to find all paths from the start vertex
map<pair<int, int>, vector<pair<int, int>>> Graph::BFS(pair<int, int> start) {
    map<pair<int, int>, vector<pair<int, int>>> paths;
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;

    q.push(start);
    visited.insert(start);
    paths[start] = {start};

    while (!q.empty()) {// While there are vertices to process
        pair<int, int> u = q.front();// Get the front vertex
        q.pop();// Remove it from the queue

        for (const auto& v : adjList[u]) {// For each neighbor of u
            // If v has not been visited, add it to the queue
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                q.push(v);
                paths[v] = paths[u];      // Copy the path to u
                paths[v].push_back(v); // Add v to the path
            }
        }
    }
    return paths;
}

#include "Graph1.h"

//gets a vertex and returns the index in the vector
int Graph1::findVertexIndex(const pair<int, int>& u) {
    auto it = vertexToIndex.find(u);
    if (it != vertexToIndex.end()) {  // Key exists
        return it->second;            // Return the index
    }
    else {                          // Key doesn't exist
        return -1;                    // Return -1 (not found)
    }
}

//creates a graph with the relevant vertexes
void Graph1::MakeEmptyGraph(int n) {
    adjList.clear();
    vertexToIndex.clear();  // Reset the map
    for (int i = 0; i <= getSmallJug(); i++) {
        for (int j = 0; j <= getLargeJug(); j++) {
            pair<int, int> vertex = { i, j };
            adjList.push_back({ vertex, {} });
            vertexToIndex[vertex] = adjList.size() - 1;  // Store index
        }
    }
}

//adds an edge to the graph
void Graph1::AddEdge(pair<int, int> u, pair<int, int> v) {
    int index = findVertexIndex(u);
    if (index != -1) {//found
        adjList[index].second.push_back(v);
        adjList[index].second.sort();
    }
}

//returns the edges list of a vertex
list<pair<int, int>> Graph1::GetAdjList(pair<int, int> u) {
    int index = findVertexIndex(u);
    if (index != -1) {
        return adjList[index].second;
    }
    return {}; // Empty if not found
}

//adds all possible edges to the graph
void Graph1::addAllPossibleEdges() {
    for (int i = 0; i < adjList.size(); i++) {
        pair<int, int> u = adjList[i].first;
        list<pair<int, int>> neighbors = CalculateAdjList(u);
        adjList[i].second = neighbors;  // Direct access (no findVertexIndex needed)
    }
    // Optional: Sort if required
    for (auto& entry : adjList) {
        entry.second.sort();
    }
}

//runs the BFS algorithem on a graph
map<pair<int, int>, vector<pair<int, int>>> Graph1::BFS(pair<int, int> start, pair<int, int> goal) {

    map<pair<int, int>, vector<pair<int, int>>> paths;
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;

    q.push(start);
    visited.insert(start);
    paths[start] = { start };

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        list<pair<int, int>> neighbors = GetAdjList(u);
        for (const auto& v : neighbors) {
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                q.push(v);
                paths[v] = paths[u];
                paths[v].push_back(v);
            }
        }
    }

    return paths;
}

//solves the problem of 2 jugs and prints the operations that are needed and number of operations
void Graph1::solveWaterJug(int smallJug, int largeJug, int W) {
    auto start = chrono::high_resolution_clock::now();

    pair<int, int> startVertex = { 0, 0 };
    pair<int, int> goalVertex = { 0, W };
    // BFS to find the path
    auto BFSpaths = BFS(startVertex, goalVertex);

    if (BFSpaths.find(goalVertex) == BFSpaths.end()) {
        cout << "No solution." << endl;
    }
    else {
        cout << "Number of operations: " << BFSpaths[goalVertex].size() - 1 << endl;
        cout << "Operations:" << endl;
        for (int i = 1; i < BFSpaths[goalVertex].size(); i++) {
            cout << i << ". " << GetOperation(BFSpaths[goalVertex][i - 1], BFSpaths[goalVertex][i], smallJug, largeJug) << endl;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    if (getShowTime()) {
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Function took " << duration.count() << " microseconds." << endl;
    }
}

#include "Utils.h"
#include "Graph.h"
#include <iostream>
#include <chrono>
using namespace std;

void solveWaterJug1(int largeJug, int smallJug, int W, bool showTime) {
    auto start = chrono::high_resolution_clock::now();
    // Create the graph
    Graph graph;
    graph.MakeEmptyGraph(largeJug, smallJug);
    graph.AddAllPossibleEdges(largeJug, smallJug);

    pair<int, int> startVertex = { 0, 0 };
    pair<int, int> goalVertex = { 0, W };
    // BFS to find the path
    auto BFSpaths = graph.BFS(startVertex);

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

    if (showTime) {
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Function took " << duration.count() << " microseconds." << endl;
    }
}

string GetOperation(pair<int, int> from, pair<int, int> to, int smallJug, int largeJug) {
    int fromSmall = from.first;
    int fromLarge = from.second;
    int toSmall = to.first;
    int toLarge = to.second;

    // 1. Fill small jug
    if (toSmall == smallJug && toLarge == fromLarge && fromSmall < smallJug)
        return "Fill small jug";

    // 2. Fill large jug
    if (toLarge == largeJug && toSmall == fromSmall && fromLarge < largeJug)
        return "Fill large jug";

    // 3. Empty small jug
    if (toSmall == 0 && toLarge == fromLarge && fromSmall > 0)
        return "Empty small jug";

    // 4. Empty large jug
    if (toLarge == 0 && toSmall == fromSmall && fromLarge > 0)
        return "Empty large jug";

    // 5. Pour small into large
    if (fromSmall > 0 && fromLarge < largeJug) {
        int pour = min(fromSmall, largeJug - fromLarge);
        if (toSmall == fromSmall - pour && toLarge == fromLarge + pour)
            return "Transfer from small jug to large jug";
    }

    // 6. Pour large into small
    if (fromLarge > 0 && fromSmall < smallJug) {
        int pour = min(fromLarge, smallJug - fromSmall);
        if (toLarge == fromLarge - pour && toSmall == fromSmall + pour)
            return "Transfer from large jug to small jug";
    }

    return "Unknown operation"; // fallback
}
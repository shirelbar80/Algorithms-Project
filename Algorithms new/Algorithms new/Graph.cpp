#include "Graph.h"

//from 2 vertex tells the operation
string Graph::GetOperation(pair<int, int> from, pair<int, int> to, int smallJug, int largeJug) {
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

//calculates the neighbors list of vertex u
list<pair<int, int>> Graph::CalculateAdjList(pair<int, int> u) {
    list<pair<int, int>> neighbors;
    int uSmallJug = u.first;
    int uLargeJug = u.second;
    int goalSmallJug = getSmallJug();
    int goalLargeJug = getLargeJug();

    // 1. Fill small jug
    neighbors.push_back({ goalSmallJug, uLargeJug });

    // 2. Fill large jug
    neighbors.push_back({ uSmallJug, goalLargeJug });

    // 3. Empty small jug
    neighbors.push_back({ 0, uLargeJug });

    // 4. Empty large jug
    neighbors.push_back({ uSmallJug, 0 });

    // 5. Pour small into large
    int pour = min(uSmallJug, goalLargeJug - uLargeJug);
    neighbors.push_back({ uSmallJug - pour, uLargeJug + pour });

    // 6. Pour large into small
    pour = min(uLargeJug, goalSmallJug - uSmallJug);
    neighbors.push_back({ uSmallJug + pour, uLargeJug - pour });

    neighbors.sort(); // sort list lexicographic order

    return neighbors;
}






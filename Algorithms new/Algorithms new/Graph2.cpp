#include "Graph2.h"

//solves the problem of 2 jugs and prints the operations that are needed and number of operations - method 2
void Graph2::solveWaterJug(int smallJug, int largeJug, int W)
{
    auto start = chrono::high_resolution_clock::now();

    pair<int, int> startState = { 0, 0 };
    unordered_set<string> visited;//visited vertexes
    unordered_map<string, string> parent;//the parent of the vertex
    queue<pair<int, int>> q;//queue for BFS algorithem

    auto toKey = [](pair<int, int> p) {//lamda function to turn a pair into a string
        return to_string(p.first) + "," + to_string(p.second);
    };

    q.push(startState);
    visited.insert(toKey(startState));
    parent[toKey(startState)] = toKey({ -1, -1 });

    pair<int, int> goal = { -1, -1 };//goal vertex - initialize it to a dummy vertex

    while (!q.empty()) {//until the queue is empty
        pair<int, int> u = q.front();//we get the first elementt from the queue
        q.pop();

        if (u.second == W && u.first == 0) {//if it is the goal set the goal to u
            goal = u;
            break;
        }

        for (auto v : CalculateAdjList(u)) {//we get the list of neighbors for u -> go through each vertex
            if (visited.find(toKey(v)) == visited.end()) {//if we havent visited the vertex
                visited.insert(toKey(v));//put it in visited
                parent[toKey(v)] = toKey(u);//u is the parent of v
                q.push(v);//put v in queue
            }
        }
    }

    if (goal == make_pair(-1, -1)) {//if we didnt reach the goal vertex
        cout << "No solution." << endl;
    }
    else {//we reached the goal
        stack<pair<int, int>> path;//path to the goal vertex
        pair<int, int> current = goal;
        while (current != make_pair(-1, -1)) {//until we reach the end-> going through the parents
            path.push(current);
            current = fromString(parent[toKey(current)]);
        }

        cout << "Number of operations: " << path.size() - 1 << endl;
        cout << "Operations:" << endl;

        int step = 1;
        pair<int, int> prev = path.top(); 
        path.pop();
        while (!path.empty()) {//until it is empty
            pair<int, int> curr = path.top(); 
            path.pop();
                        
            cout << step++ << ". " << GetOperation(prev, curr, smallJug, largeJug) << endl;
            
            prev = curr;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    if (getShowTime()) {//prints time
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Function took " << duration.count() << " microseconds." << endl;
    }

}

//adds a edge to the graph
void Graph2::AddEdge(pair<int, int> u, pair<int, int> v) {
    adjList[u].push_back(v);
    adjList[u].sort(); // Lexicographic order
}

//returns the list of neighbors for vertex u
list<pair<int, int>> Graph2::GetAdjList(pair<int, int> u) {
    return adjList[u];
}

// gets the string of the pair and returns the pair
pair<int, int> Graph2::fromString(const string& s) {
    size_t comma = s.find(',');
    int a = stoi(s.substr(0, comma));
    int b = stoi(s.substr(comma + 1));
    return { a, b };
}




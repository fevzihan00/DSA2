#include <iostream>
#include <vector>
using namespace std;


bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& color, int c, int V) {
    for (int i = 0; i < V; ++i) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int M, vector<int>& color, int v, int V) {
    
    if (v == V) {
        return true;
    }

    
    for (int c = 1; c <= M; ++c) {
        
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            
            if (graphColoringUtil(graph, M, color, v + 1, V)) {
                return true;
            }

            
            color[v] = 0;
        }
    }

    
    return false;
}


bool graphColoring(vector<vector<int>>& graph, int M, int V) {
    
    vector<int> color(V, 0);

    
    if (graphColoringUtil(graph, M, color, 0, V)) {
        return true;
    }
    return false;
}

int main() {
    int N = 4; 
    int M = 3; 
    int E = 5; 

    vector<pair<int, int>> edges = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2} };

    
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (auto& edge : edges) {
        graph[edge.first][edge.second] = 1;
        graph[edge.second][edge.first] = 1;
    }

    if (graphColoring(graph, M, N)) {
        cout << "1\n"; 
    }
    else {
        cout << "0\n"; 
    }

    return 0;
}

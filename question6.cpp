#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool isSafe(int x, int y, vector<vector<int>>& m, vector<vector<bool>>& visited, int N) {
    return (x >= 0 && x < N&& y >= 0 && y < N&& m[x][y] == 1 && !visited[x][y]);
}


void findPaths(int x, int y, vector<vector<int>>& m, int N, vector<string>& paths, string& path, vector<vector<bool>>& visited) {
    
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    
    visited[x][y] = true;

   
    if (isSafe(x + 1, y, m, visited, N)) {
        path.push_back('D');
        findPaths(x + 1, y, m, N, paths, path, visited);
        path.pop_back();
    }

    
    if (isSafe(x, y - 1, m, visited, N)) {
        path.push_back('L');
        findPaths(x, y - 1, m, N, paths, path, visited);
        path.pop_back();
    }

    
    if (isSafe(x, y + 1, m, visited, N)) {
        path.push_back('R');
        findPaths(x, y + 1, m, N, paths, path, visited);
        path.pop_back();
    }

    
    if (isSafe(x - 1, y, m, visited, N)) {
        path.push_back('U');
        findPaths(x - 1, y, m, N, paths, path, visited);
        path.pop_back();
    }

    
    visited[x][y] = false;
}


vector<string> findPath(vector<vector<int>>& m, int N) {
    vector<string> paths;
    if (m[0][0] == 0 || m[N - 1][N - 1] == 0) {
        return paths;
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    string path = "";

    findPaths(0, 0, m, N, paths, path, visited);

    
    sort(paths.begin(), paths.end());

    return paths;
}

int main() {
    int N = 4;
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = findPath(m, N);
    for (string path : result) {
        cout << path << " ";
    }

    return 0;
}

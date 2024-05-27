#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Direction vectors for 8 possible movements (left, right, up, down, and diagonals)
int dirX[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dirY[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool isSafe(int x, int y, int R, int C, vector<vector<bool>>& visited) {
    return (x >= 0 && x < R&& y >= 0 && y < C && !visited[x][y]);
}

bool searchWord(vector<vector<char>>& board, int R, int C, string& word, int index, int x, int y, vector<vector<bool>>& visited) {
    if (index == word.size()) return true; // All characters found

    if (!isSafe(x, y, R, C, visited) || board[x][y] != word[index]) return false;

    visited[x][y] = true; // Mark the cell as visited

    // Try all 8 directions
    for (int dir = 0; dir < 8; ++dir) {
        int newX = x + dirX[dir];
        int newY = y + dirY[dir];

        if (searchWord(board, R, C, word, index + 1, newX, newY, visited)) {
            return true;
        }
    }

    visited[x][y] = false; // Unmark the cell as visited for backtracking
    return false;
}

vector<string> findWords(vector<vector<char>>& board, int R, int C, unordered_set<string>& dictionary) {
    vector<string> result;
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (const string& word : dictionary) {
        bool found = false;
        for (int i = 0; i < R && !found; ++i) {
            for (int j = 0; j < C && !found; ++j) {
                if (board[i][j] == word[0] && searchWord(board, R, C, word, 0, i, j, visited)) {
                    result.push_back(word);
                    found = true;
                }
            }
        }
    }

    return result;
}

int main() {
    // Example usage
    unordered_set<string> dictionary = { "CAT" };
    vector<vector<char>> board = {
        {'C', 'A', 'P'},
        {'A', 'N', 'D'},
        {'T', 'I', 'E'}
    };

    int R = 3, C = 3;

    vector<string> wordsFound = findWords(board, R, C, dictionary);

    for (const string& word : wordsFound) {
        cout << word << endl;
    }

    return 0;
}

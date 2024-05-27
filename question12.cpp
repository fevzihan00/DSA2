#include <iostream>
#include <vector>

using namespace std;

int countSpecialSequences(int m, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
    for (int j = 1; j <= m; ++j) {
        dp[1][j] = 1;
    }

   
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            
            for (int k = j / 2; k <= j; ++k) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

   
    int total = 0;
    for (int j = 1; j <= m; ++j) {
        total += dp[n][j];
    }

    return total;
}

int main() {
    int m = 10;
    int n = 4;
    cout << countSpecialSequences(m, n) << endl; 

    return 0;
}

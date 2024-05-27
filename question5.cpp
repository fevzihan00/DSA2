#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
    int first, second;
};

bool comparePairs(Pair a, Pair b) {
    return a.first < b.first;
}

int maxChainLen(struct Pair arr[], int n) {
    sort(arr, arr + n, comparePairs);

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].second < arr[i].first && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int N = 5;
    Pair arr[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };

    cout << maxChainLen(arr, N) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findLongestChain(vector<pair<int, int>>& pairs) {
  
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        });

    int n = pairs.size();
    int longestChainLength = 0;
    int currentEnd = INT_MIN;

    
    for (int i = 0; i < n; ++i) {
        if (pairs[i].first > currentEnd) {
           
            longestChainLength++;
            currentEnd = pairs[i].second;  
        }
    }

    return longestChainLength;
}

int main() {
    int N = 5;
    vector<pair<int, int>> pairs = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };

    int result = findLongestChain(pairs);
    cout << "The longest chain length is: " << result << endl;

    return 0;
}

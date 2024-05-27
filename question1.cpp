#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;      
    int dead;    
    int profit;  
};


bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

pair<int, int> JobScheduling(Job arr[], int n) {
  
    sort(arr, arr + n, comparison);

    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].dead > maxDeadline) {
            maxDeadline = arr[i].dead;
        }
    }

    
    vector<bool> timeSlots(maxDeadline, false);

    int numJobs = 0;
    int totalProfit = 0;

    
    for (int i = 0; i < n; i++) {
        
        for (int j = min(maxDeadline, arr[i].dead) - 1; j >= 0; j--) {
            if (!timeSlots[j]) {
                
                timeSlots[j] = true;
                numJobs++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    return make_pair(numJobs, totalProfit);
}

int main() {
    int n = 4;
    Job arr[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };

    pair<int, int> result = JobScheduling(arr, n);
    cout << result.first << " " << result.second << endl; 

    return 0;
}

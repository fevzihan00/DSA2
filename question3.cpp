#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return (a.deadline < b.deadline);
}

vector<int> JobScheduling(int N, vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    vector<int> dp(N + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (dp[j] == 0) {
                dp[j] = dp[j - 1] + jobs[i].profit;
                break;
            }
        }
    }

    int maxProfit = *max_element(dp.begin(), dp.end());
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (dp[i] > 0) {
            count++;
        }
    }

    return { count, maxProfit };
}

int main() {
    int N = 5;
    vector<Job> jobs = { {1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15} };

    vector<int> result = JobScheduling(N, jobs);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}

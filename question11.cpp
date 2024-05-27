#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(const vector<int>& pages, int numStudents, int maxPages) {
    int students = 1;
    int currentPage = 0;
    for (int page : pages) {
        if (currentPage + page > maxPages) {
            currentPage = page;
            students++;
            if (students > numStudents) {
                return false;
            }
        }
        else {
            currentPage += page;
        }
    }
    return true;
}

int minPages(vector<int>& pages, int numStudents) {
    int totalPages = 0;
    int maxPage = 0;

    for (int page : pages) {
        totalPages += page;
        maxPage = max(maxPage, page);
    }

    int low = maxPage;
    int high = totalPages;

    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isValid(pages, numStudents, mid)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int N = 4;
    vector<int> A = { 12, 34, 67, 90 };
    int M = 2;

    int result = minPages(A, M);
    cout << "Output: " << result << endl;

    return 0;
}

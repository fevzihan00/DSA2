#include <iostream>
#include <vector>

using namespace std;


int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n = arr1.size();
    int m = arr2.size();

   
    if (k > n + m) {
        return -1; 
    }

    
    if (n == 0) return arr2[k - 1];
    if (m == 0) return arr1[k - 1];
    if (k == 1) return min(arr1[0], arr2[0]);

    int i = min(n, k / 2);
    int j = min(m, k / 2);

    
    if (arr1[i - 1] < arr2[j - 1]) {
        
        vector<int> subArr1(arr1.begin() + i, arr1.end());
        return kthElement(subArr1, arr2, k - i);
    }
    else {
        
        vector<int> subArr2(arr2.begin() + j, arr2.end());
        return kthElement(arr1, subArr2, k - j);
    }
}

int main() {
    vector<int> arr1 = { 2, 3, 6, 7, 9 };
    vector<int> arr2 = { 1, 4, 8, 10 };
    int k = 5;

    int result = kthElement(arr1, arr2, k);

    if (result != -1) {
        cout << "The " << k << "th element of the merged sorted array is: " << result << endl;
    }
    else {
        cout << "Invalid input: k is greater than the total number of elements." << endl;
    }

    return 0;
}

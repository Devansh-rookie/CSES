// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> findIndices(const vector<int>& arr) {
//     vector<int> indices;
//     int n = arr.size();

//     for (int i = 0; i < n; ++i) {
//         // Handle edge cases for the first and last elements
//         int left = (i > 0) ? arr[i - 1] : INT_MIN;
//         int right = (i < n - 1) ? arr[i + 1] : INT_MIN;

//         // Check if the current element is greater than or equal to its neighbors
//         if (arr[i] >= left && arr[i] >= right) {
//             indices.push_back(i);
//         }
//     }

//     return indices;
// }

// int main() {
//     vector<int> arr = {352, 266, 409, 22, 424, 716, 797, 749, 985, 485, 638, 521, 16, 82, 17};
//     vector<int> indices = findIndices(arr);

//     cout << "Indices: ";
//     for (int index : indices) {
//         cout << index << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

// long long countValidSubsegments(int x, const vector<int>& arr) {
//     int n = arr.size();
//     long long count = 0;
//     int g = 0;
//     int start = 0;

//     for (int end = 0; end < n; ++end) {
//         g += arr[end];
//         while (g > x) {
//             g -= arr[start];
//             start++;
//         }
//         count += (end - start + 1);
//     }

//     return count;
// }

long long countValidSubsegments(int x, const vector<int>& arr) {
    int n = arr.size();
    long long count = 0;
    int g = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        g += arr[end];
        while (g > x) {
            g -= arr[start];
            start++;
        }
        if (g != 0) {
            count += (end - start + 1);
        }
    }

    return count;
}

int main(){
    vector<int> some = {1, 1, 1, 1};
    cout << countValidSubsegments(2, some) << endl; 

    return 0;
}
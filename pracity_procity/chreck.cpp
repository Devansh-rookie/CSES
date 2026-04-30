// // // // #include <iostream>
// // // // #include <vector>
// // // // using namespace std;

// // // // class Solution {
// // // // public:
// // // //     int calculateCells(int A, int B, int C) {
// // // //         const int MOD = 1e9 + 7;
// // // //         vector<long long> born_on_day(A + 1, 0);
// // // //         born_on_day[1] = 1; // 1 cell born on day 1

// // // //         for (int day = 2; day <= A; day++) {
// // // //             long long new_births = 0;

// // // //             // Check all previous days for cells that can reproduce today
// // // //             for (int birth_day = 1; birth_day < day; birth_day++) {
// // // //                 int age = day - birth_day;
// // // //                 // Cell can reproduce if: age >= B AND cell is still alive (age < C)
// // // //                 if (age >= B && age < C) {
// // // //                     new_births = (new_births + born_on_day[birth_day]) % MOD;
// // // //                 }
// // // //             }

// // // //             born_on_day[day] = new_births;
// // // //         }

// // // //         // Count all living cells on day A
// // // //         long long total_alive = 0;
// // // //         for (int birth_day = 1; birth_day <= A; birth_day++) {
// // // //             int age_on_day_A = A - birth_day + 1;
// // // //             if (age_on_day_A < C) { // Cell is still alive
// // // //                 total_alive = (total_alive + born_on_day[birth_day]) % MOD;
// // // //             }
// // // //         }

// // // //         return total_alive;
// // // //     }
// // // // };

// // // // int main() {
// // // //     Solution solution;

// // // //     // Test Case 1: A=5, B=2, C=3
// // // //     int A1 = 5, B1 = 2, C1 = 3;
// // // //     int result1 = solution.calculateCells(A1, B1, C1);
// // // //     cout << "Test Case 1 (A=" << A1 << ", B=" << B1 << ", C=" << C1 << "): " << result1 << endl;

// // // //     // Test Case 2: A=5, B=1, C=5
// // // //     int A2 = 5, B2 = 1, C2 = 5;
// // // //     int result2 = solution.calculateCells(A2, B2, C2);
// // // //     cout << "Test Case 2 (A=" << A2 << ", B=" << B2 << ", C=" << C2 << "): " << result2 << endl;

// // // //     // Interactive input
// // // //     cout << "\nEnter your own test case:" << endl;
// // // //     int A, B, C;
// // // //     cout << "Enter A (day to find cells): ";
// // // //     cin >> A;
// // // //     cout << "Enter B (days before reproduction): ";
// // // //     cin >> B;
// // // //     cout << "Enter C (lifespan in days): ";
// // // //     cin >> C;

// // // //     int result = solution.calculateCells(A, B, C);
// // // //     cout << "Number of virus cells on day " << A << ": " << result << endl;

// // // //     return 0;
// // // // }


// // // #include <iostream>
// // // #include <vector>

// // // class Solution {
// // // public:
// // //     int calculateCells(int A, int B, int C);
// // // };

// // // int Solution::calculateCells(int A, int B, int C) {
// // //     long long MOD = 1e9 + 7;

// // //     // prefix_born[i] stores the sum of new cells born from day 1 to day i.
// // //     std::vector<long long> prefix_born(A + 1, 0);

// // //     // On day 1, one cell is present.
// // //     // So, born[1] = 1.
// // //     prefix_born[1] = 1;

// // //     for (int i = 2; i <= A; ++i) {
// // //         // Calculate the number of new cells born on day i.
// // //         // born[i] = sum(born[d]) for d from i-C+1 to i-B.
// // //         // In terms of prefix sums: born[i] = prefix_born[i-B] - prefix_born[i-C].

// // //         long long upper_sum = 0;
// // //         if (i - B > 0) {
// // //             upper_sum = prefix_born[i - B];
// // //         }

// // //         long long lower_sum = 0;
// // //         if (i - C > 0) {
// // //             lower_sum = prefix_born[i - C];
// // //         }

// // //         // Handle negative result from subtraction with modulo.
// // //         long long new_born_today = (upper_sum - lower_sum + MOD) % MOD;

// // //         // Update the prefix sum for day i.
// // //         prefix_born[i] = (prefix_born[i - 1] + new_born_today) % MOD;
// // //     }

// // //     // Total living cells on day A are those born from day A-C+1 to A.
// // //     // Total(A) = prefix_born[A] - prefix_born[A-C].

// // //     long long total_cells_sum = prefix_born[A];
// // //     long long dead_cells_sum = 0;
// // //     if (A - C > 0) {
// // //         dead_cells_sum = prefix_born[A - C];
// // //     }

// // //     long long result = (total_cells_sum - dead_cells_sum + MOD) % MOD;

// // //     return (int)result;
// // // }

// // // // Example Usage (for testing)
// // // int main() {
// // //     Solution sol;

// // //     // Example 1: A=5, B=2, C=3 -> Output: 2
// // //     std::cout << "Example 1 Output: " << sol.calculateCells(5, 2, 3) << std::endl;

// // //     // Example 2: A=5, B=1, C=5 -> Output: 16
// // //     std::cout << "Example 2 Output: " << sol.calculateCells(5, 1, 5) << std::endl;

// // //     return 0;
// // // }
// // #include <bits/stdc++.h>
// // using namespace std;

// // class Solution {
// // public:
// //     vector<long long> mostFrequentBooks(vector<int>& A, vector<int>& B) {
// //         const int n = A.size();
// //         unordered_map<int, long long> cnt;          // current copies of each ID
// //         multiset<long long> mx;                     // multiset of positive counts
// //         vector<long long> res;
// //         res.reserve(n);

// //         for (int i = 0; i < n; ++i) {
// //             int id = A[i];
// //             long long delta = B[i];

// //             // erase old count from multiset if it was positive
// //             auto it = cnt.find(id);
// //             if (it != cnt.end() && it->second > 0) {
// //                 mx.erase(mx.find(it->second));
// //             }

// //             // update count
// //             long long newCnt = (it == cnt.end() ? 0 : it->second) + delta;
// //             cnt[id] = newCnt;

// //             // insert new count if positive
// //             if (newCnt > 0) mx.insert(newCnt);

// //             // record current maximum
// //             res.push_back(mx.empty() ? 0LL : *mx.rbegin());
// //         }
// //         return res;
// //     }
// // };
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<long long> mostFrequentBooks(vector<int>& A, vector<int>& B) {
//         const int n = A.size();
//         unordered_map<int, long long> cnt;          // current copies of each ID
//         multiset<long long> mx;                     // multiset of positive counts
//         vector<long long> res;
//         res.reserve(n);

//         for (int i = 0; i < n; ++i) {
//             int id = A[i];
//             long long delta = B[i];

//             // erase old count from multiset if it was positive
//             auto it = cnt.find(id);
//             if (it != cnt.end() && it->second > 0) {
//                 mx.erase(mx.find(it->second));
//             }

//             // update count
//             long long newCnt = (it == cnt.end() ? 0 : it->second) + delta;
//             cnt[id] = newCnt;

//             // insert new count if positive
//             if (newCnt > 0) mx.insert(newCnt);

//             // record current maximum
//             res.push_back(mx.empty() ? 0LL : *mx.rbegin());
//         }
//         return res;
//     }
// };
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> mostFrequentBooks(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        unordered_map<int, long long> cnt;          // current copies of each ID
        multiset<long long> mx;                     // multiset of positive counts
        vector<long long> res;
        res.reserve(n);

        for (int i = 0; i < n; ++i) {
            int id = A[i];
            long long delta = B[i];

            // erase old count from multiset if it was positive
            auto it = cnt.find(id);
            if (it != cnt.end() && it->second > 0) {
                mx.erase(mx.find(it->second));
            }

            // update count
            long long newCnt = (it == cnt.end() ? 0 : it->second) + delta;
            cnt[id] = newCnt;

            // insert new count if positive
            if (newCnt > 0) mx.insert(newCnt);

            // record current maximum
            res.push_back(mx.empty() ? 0LL : *mx.rbegin());
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> A1 = {2, 3, 2, 1};
    vector<int> B1 = {3, 2, -3, 1};
    vector<long long> result1 = solution.mostFrequentBooks(A1, B1);

    cout << "Test Case 1:" << endl;
    cout << "Input: A = [2, 3, 2, 1], B = [3, 2, -3, 1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // Test Case 2
    vector<int> A2 = {5, 5, 3};
    vector<int> B2 = {2, -2, 1};
    vector<long long> result2 = solution.mostFrequentBooks(A2, B2);

    cout << "Test Case 2:" << endl;
    cout << "Input: A = [5, 5, 3], B = [2, -2, 1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // Custom test case
    cout << "Enter your own test case:" << endl;
    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    vector<int> A(n), B(n);
    cout << "Enter array A (book IDs): ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter array B (changes): ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<long long> customResult = solution.mostFrequentBooks(A, B);
    cout << "Result: [";
    for (int i = 0; i < customResult.size(); i++) {
        cout << customResult[i];
        if (i < customResult.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

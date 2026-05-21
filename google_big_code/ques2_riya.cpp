#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

long long solve(int N, int K, vector<long long> A) {
    // Pair stores {Configuration Value, Original Index}
    // Using long long for index prevents any hidden 32-bit arithmetic overflow later
    vector<pair<long long, long long>> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = {A[i], (long long)i};
    }

    // Group identical configurations together, natively sorted by their original index
    sort(arr.begin(), arr.end());

    long long max_cost = 0;

    for (int i = 0; i < N; ) {
        int j = i;
        long long current_sum = 0;

        // Find the bounds of the current configuration group and accumulate their indices
        while (j < N && arr[j].first == arr[i].first) {
            current_sum += arr[j].second;
            j++;
        }

        long long m = j - i;                    // Number of occurrences
        long long first_pos = arr[i].second;    // p[0]
        long long last_pos = arr[j - 1].second; // p[m-1]

        // A valid migration requires at least 2 servers and a gap >= K
        if (m >= 2 && last_pos - first_pos >= K) {
            // Remove the last position from the sum (since the formula iterates up to a_{i+1}-1)
            current_sum -= last_pos;

            // Formula: (m - 1) * p[m-1] - sum(p[0] ... p[m-2])
            long long current_cost = last_pos * (m - 1) - current_sum;

            // Track the maximum cost seen globally
            if (current_cost > max_cost) {
                max_cost = current_cost;
            }
        }

        // Jump to the next distinct configuration value
        i = j;
    }

    return max_cost;
}

void run_test_cases() {
    // Test Case 1: Sample Input from the problem description
    // For value 5: indices [0, 2, 4]. Cost = (3-1)*4 - (0+2) = 8 - 2 = 6.
    // For value 3: indices [1, 3, 5]. Target gap satisfied but cost is lower/equal. Max cost = 6.
    assert(solve(6, 2, {5, 3, 5, 3, 5, 3}) == 6);
    cout << "Test Case 1 Passed!" << endl;

    // Test Case 2: No valid migrations possible (Gap condition K is too large)
    // Value 1 appears at 0, 1, 2. Max gap is 2 - 0 = 2. K is 3.
    assert(solve(3, 3, {1, 1, 1}) == 0);
    cout << "Test Case 2 Passed!" << endl;

    // Test Case 3: All servers have unique configurations
    // No configuration appears more than once, so migration is impossible.
    assert(solve(4, 1, {1, 2, 3, 4}) == 0);
    cout << "Test Case 3 Passed!" << endl;

    // Test Case 4: Multiple competing configurations
    // Value 10: indices [0, 2, 4] -> Cost: (2 * 4) - (0 + 2) = 6
    // Value 20: indices [1, 3, 5, 6] -> Cost: (3 * 6) - (1 + 3 + 5) = 18 - 9 = 9
    assert(solve(7, 2, {10, 20, 10, 20, 10, 20, 20}) == 9);
    cout << "Test Case 4 Passed!" << endl;

    // Test Case 5: Large Gap K and many intermediate servers
    // Value 7: indices [0, 1, 2, 3, 4, 5]
    // Max cost calculation: (6-1)*5 - (0+1+2+3+4) = 25 - 10 = 15.
    assert(solve(6, 5, {7, 7, 7, 7, 7, 7}) == 15);
    cout << "Test Case 5 Passed!" << endl;

    // Test Case 6: Exactly two occurrences satisfying exactly K gap
    // Value 99: indices [0, 3]. Gap = 3 >= K(3). Cost = (2-1)*3 - (0) = 3.
    assert(solve(4, 3, {99, 1, 2, 99}) == 3);
    cout << "Test Case 6 Passed!" << endl;

    cout << "All test cases passed successfully!" << endl;
}

int main() {
    // Run the automated test cases
    run_test_cases();
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int x = 0, x_pos = -1;

        // Read the array and identify the special element `x` and its position
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != 1 && a[i] != -1) {
                x = a[i];
                x_pos = i;
            }
        }

        // Create a set to store all unique subarray sums
        set<long long> result_sums;

        // Step 1: Calculate subarray sums from the left side (before `x`)
        long long current_sum = 0;
        result_sums.insert(0);  // empty subarray
        for (int i = 0; i < x_pos; i++) {
            current_sum += a[i];
            result_sums.insert(current_sum);
        }

        // Step 2: Calculate subarray sums from the right side (after `x`)
        current_sum = 0;
        for (int i = n - 1; i > x_pos; i--) {
            current_sum += a[i];
            result_sums.insert(current_sum);
        }

        // Step 3: Consider the sums that involve `x` itself
        // We need to combine sums from the left part, x, and right part.
        set<long long> left_sums = {0};
        current_sum = 0;
        for (int i = 0; i < x_pos; i++) {
            current_sum += a[i];
            left_sums.insert(current_sum);
        }

        set<long long> right_sums = {0};
        current_sum = 0;
        for (int i = n - 1; i > x_pos; i--) {
            current_sum += a[i];
            right_sums.insert(current_sum);
        }

        // Add the combinations of left sums + x + right sums
        for (auto left : left_sums) {
            for (auto right : right_sums) {
                result_sums.insert(left + x + right);
            }
        }

        // Output the result
        cout << result_sums.size() << endl;
        for (auto sum : result_sums) {
            cout << sum << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}

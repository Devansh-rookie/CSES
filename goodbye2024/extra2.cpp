#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> intervals(n); // Store intervals {l, r}
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }

        map<int, bool> used; // Track used values
        vector<int> result(n, 0); // Result array

        for (int i = 0; i < n; ++i) {
            int l = intervals[i].first;
            int r = intervals[i].second;

            bool found = false;
            for (int val = l; val <= r; ++val) {
                if (!used[val]) {
                    used[val] = true; // Mark the value as used
                    result[i] = 1;    // Mark the interval as unique
                    found = true;
                    break;
                }
            }

            if (!found) {
                result[i] = 0; // No valid value found for this interval
            }
        }

        // Output the result for this test case
        for (int bit : result) {
            cout << bit;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

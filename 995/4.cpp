#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        long long total_sum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_sum += a[i];
        }

        // Initialize the count of interesting pairs
        long long interesting_pairs = 0;

        // Sort the array for efficient two-pointer calculation
        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            long long remaining_sum = total_sum - a[i];
            long long lb = x - remaining_sum;
            long long ub = y - remaining_sum;

            // Use binary search to count valid pairs
            long long start = *lower_bound(a.begin() + i + 1, a.end(), lb);
            long long  end = *upper_bound(a.begin() + i + 1, a.end(), ub);

            interesting_pairs += end - start;
        }

        cout << interesting_pairs << '\n';
    }

    return 0;
}

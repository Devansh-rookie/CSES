// #include<bits/stdc++.h>
// using namespace std;

// void setIO(string name = "") {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     if (name.size()) {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

// long long countShareCompatibleWindows(int n, int m, const std::vector<int>& cannotShare_from, const std::vector<int>& cannotShare_to) {
//     // adj[v] will store all u's such that (u, v) is a conflict and u < v.
//     std::vector<std::vector<int>> adj(n + 1);
//     for (int i = 0; i < m; ++i) {
//         int u = cannotShare_from[i];
//         int v = cannotShare_to[i];
//         if (u < v) {
//             adj[v].push_back(u);
//         } else {
//             adj[u].push_back(v);
//         }
//     }

//     long long total_count = 0;
//     int left_bound = 1; // The minimum valid start index for a window

//     // Iterate through all possible window end points 'j'
//     for (int j = 1; j <= n; ++j) {
//         // Check if the current endpoint 'j' introduces new constraints
//         // on the window's start point.
//         // For each conflict (u, j) where u < j, the window must start after u.
//         for (int conflict_start : adj[j]) {
//             left_bound = std::max(left_bound, conflict_start + 1);
//         }

//         // For the current end point 'j', any window [i, j] is valid
//         // if its start point 'i' is >= left_bound.
//         // The possible start points are left_bound, left_bound + 1, ..., j.
//         // The number of such points is (j - left_bound + 1).
//         if (j >= left_bound) {
//             total_count += (j - left_bound + 1);
//         }
//     }

//     return total_count;
// }


// int main() {
//     setIO("check");

//     int n1 = 3;
//         int m1 = 3;
//         std::vector<int> from1 = {2, 1, 3};
//         std::vector<int> to1 = {3, 3, 1};
//         std::cout << "Example 1 Output: " << countShareCompatibleWindows(n1, m1, from1, to1) << std::endl; // Expected: 4

//         // Example 2
//         int n2 = 4;
//         int m2 = 2;
//         std::vector<int> from2 = {1, 2};
//         std::vector<int> to2 = {2, 4};
//         std::cout << "Example 2 Output: " << countShareCompatibleWindows(n2, m2, from2, to2) << std::endl; // Expected: 6 (see note)

//     return 0;
// }

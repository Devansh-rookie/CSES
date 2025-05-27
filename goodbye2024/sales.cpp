#include<bits/stdc++.h>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// int getSpecialSubarrays(vector<int>& efficiency, int k) {
//     int n = efficiency.size();
//     int count = 0;

//     for (int len = 1; len <= n; len += 2) { // only odd lengths
//         for (int i = 0; i + len <= n; ++i) {
//             int j = i + len - 1;

//             // Check if index k is inside [i...j]
//             if (i <= k && k <= j) {
//                 vector<int> subarray(efficiency.begin() + i, efficiency.begin() + j + 1);
//                 sort(subarray.begin(), subarray.end());

//                 int median = subarray[len / 2];
//                 if (median == efficiency[k]) {
//                     count++;
//                 }
//             }
//         }
//     }

//     return count;
// }


int main() {
    setIO("check");
    int n, k;
    cin >> n >> k;
    k--; // Convert to 0-based index

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int count = 0;

    // Try all possible odd lengths with a[k] as the median
    for (int m = 0; k - m >= 0 && k + m < n; ++m) {
        int start = k - m;
        int end = k + m;
        vector<int> subarray(a.begin() + start, a.begin() + end + 1);
        sort(subarray.begin(), subarray.end());
        int median = subarray[m]; // Since length = 2m + 1
        if (median == a[k]) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int minimizeDiameter(int n, int k, vector<vector<int>>& edges) {
//     vector<vector<int>> adj(n + 1);
//     vector<int> degree(n + 1, 0);

//     // Build adjacency list
//     for (auto& edge : edges) {
//         int u = edge[0], v = edge[1];
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         degree[u]++;
//         degree[v]++;
//     }

//     // Find all initial leaves
//     queue<int> q;
//     vector<bool> removed(n + 1, false);
//     for (int i = 1; i <= n; ++i) {
//         if (degree[i] == 1) {
//             q.push(i);
//         }
//     }

//     // Remove up to k individual leaf nodes
//     while (!q.empty() && k > 0) {
//         int leaf = q.front(); q.pop();

//         removed[leaf] = true;
//         k--;

//         for (int neighbor : adj[leaf]) {
//             if (!removed[neighbor]) {
//                 degree[neighbor]--;
//                 if (degree[neighbor] == 1) {
//                     q.push(neighbor);
//                 }
//             }
//         }
//     }

//     // If all nodes are removed
//     int remainingNodes = 0;
//     for (int i = 1; i <= n; ++i)
//         if (!removed[i])
//             remainingNodes++;

//     if (remainingNodes <= 1)
//         return 0;

//     // Find diameter of remaining tree using double BFS
//     function<pair<int, int>(int)> bfs = [&](int start) -> pair<int, int> {
//         vector<int> dist(n + 1, -1);
//         queue<int> q;
//         dist[start] = 0;
//         q.push(start);
//         int farthest = start;

//         while (!q.empty()) {
//             int u = q.front(); q.pop();
//             for (int v : adj[u]) {
//                 if (dist[v] == -1 && !removed[v]) {
//                     dist[v] = dist[u] + 1;
//                     q.push(v);
//                     if (dist[v] > dist[farthest])
//                         farthest = v;
//                 }
//             }
//         }

//         return {farthest, dist[farthest]};
//     };


//     // Start BFS from any remaining node
//     int start = 1;
//     while (start <= n && removed[start]) start++;

//     auto [u, _] = bfs(start);
//     auto [v, diameter] = bfs(u);

//     return diameter;
// }


// int logTransferReceiver(vector<int>& logReceiver, long long k) {
//     unordered_map<int, long long> visitedAt;  // developer -> step count
//     vector<int> path;

//     int current = 1;  // Developer 1 starts
//     long long steps = 0;

//     while (visitedAt.count(current) == 0 && steps < k) {
//         visitedAt[current] = steps;
//         path.push_back(current);
//         current = logReceiver[current - 1];  // move to the next developer
//         steps++;
//     }

//     if (steps == k) {
//         return current;
//     }

//     // Cycle detected
//     long long cycleStart = visitedAt[current];
//     long long cycleLength = steps - cycleStart;

//     // Compute remaining steps inside the cycle
//     long long cycleSteps = (k - cycleStart) % cycleLength;

//     return path[cycleStart + cycleSteps];
// }

// int main() {
//     setIO("check");
//     // int n, k;
//     // cin >> n >> k;
//     // vector<vector<int>> edges(n - 1);
//     // for (int i = 0; i < n - 1; ++i) {
//     //     int u, v;
//     //     cin >> u >> v;
//     //     edges[i] = {u, v};
//     // }

//     // cout << minimizeDiameter(n, k, edges) << endl;
//     //

//     vector<int> log = {2, 4, 1, 5, 3};
//     long long k = 6;
//     cout << logTransferReceiver(log, k);
//     return 0;
// }


// // int main() {
// //     setIO("check");
// //     vector<int> eff = {5, 3, 1, 4, 7, 7};
// //     cout << getSpecialSubarrays(eff, 3);

// //     return 0;
// // }

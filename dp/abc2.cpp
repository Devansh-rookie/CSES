// #include <iostream>
// #include <vector>
// #include <set>
// #include <unordered_map>
// using namespace std;

// void FindResult(int N, vector<pair<int, int>>& arr) {
//     vector<set<int>> winningSets = {
//         {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
//         {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
//         {0, 4, 8}, {2, 4, 6}
//     };

//     for (const auto& move : arr) {
//         int u = move.first;
//         int v = move.second;

//         int options = 0;
//         int candidate = -1;

//         for (const auto& combo : winningSets) {
//             if (combo.count(u) && combo.count(v)) {
//                 set<int> diff = combo;
//                 diff.erase(u);
//                 diff.erase(v);
//                 if (diff.size() == 1) {
//                     options++;
//                     candidate = *diff.begin();
//                 }
//             }
//         }

//         if (options == 1)
//             cout << candidate << '\n';
//         else
//             cout << "Any Move\n";
//     }
// }
// int main() {
//     // Sample input: 3 test cases
//     int N;
//     cin >> N;

//     vector<pair<int, int>> moves(N);
//     for (int i = 0; i < N; ++i) {
//         int x, y;
//         cin >> x >> y;
//         moves[i] = {x, y};
//     }

//     FindResult(N, moves);

//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, i;
    cin >> n >> i;

    // Create adjacency list and in-degree array
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    // Read dependencies
    for (int j = 0; j < i; j++) {
        int a, b;
        cin >> a >> b;
        // A depends on B, so edge from B to A
        adj[b].push_back(a);
        indegree[a]++;
    }

    // Use priority queue to ensure ascending order when multiple choices
    priority_queue<int, vector<int>, greater<int>> pq;

    // Add all nodes with 0 in-degree (no dependencies)
    for (int k = 1; k <= n; k++) {
        if (indegree[k] == 0) {
            pq.push(k);
        }
    }

    vector<int> result;

    // Kahn's algorithm for topological sorting
    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();
        result.push_back(current);

        // Reduce in-degree of dependent modules
        for (int neighbor : adj[current]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    // Check if all modules are processed (no cycle)
    if (result.size() == n) {
        for (int k = 0; k < n; k++) {
            cout << result[k];
            if (k < n - 1) cout << " ";
        }
        cout << endl;
    } else {
        cout << "NOT POSSIBLE" << endl;
    }

    return 0;
}

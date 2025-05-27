#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Topological sort function
vector<int> mergeSequences(const vector<vector<int>>& sequences) {
    unordered_map<int, unordered_set<int>> adj;  // adjacency list
    unordered_map<int, int> indegree;            // indegree count
    unordered_set<int> all_nodes;

    // Build graph
    for (const auto& seq : sequences) {
        for (int i = 0; i < seq.size(); ++i) {
            all_nodes.insert(seq[i]);
            if (i < seq.size() - 1) {
                int u = seq[i], v = seq[i + 1];
                if (adj[u].insert(v).second) { // insert only if not already present
                    indegree[v]++;
                }
                indegree[u] += 0; // ensure u is in indegree map
            }
        }
    }

    // Kahn's algorithm
    queue<int> q;
    for (int node : all_nodes) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check if all nodes are in result (i.e., no cycle)
    if (result.size() != all_nodes.size()) {
        throw runtime_error("Invalid input: cycle detected, conflicting orderings.");
    }

    return result;
}

int main() {
    vector<vector<int>> sequences = {
        {1, 2, 15, 8},
        {2, 4, 7, 8},
        {15, 9}
    };

    try {
        vector<int> merged = mergeSequences(sequences);
        for (int x : merged) cout << x << " ";
        cout << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

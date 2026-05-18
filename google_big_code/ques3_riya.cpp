#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) to efficiently find connected components
class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Attach smaller tree under root of deeper tree
            if (size[root_i] < size[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }
};

int maxFriendshipPower(int N, int M, vector<vector<int>> roads, vector<int> A) {
    DSU dsu(N);

    // Process all roads to form kingdoms
    for (const auto& edge : roads) {
        dsu.unite(edge[0], edge[1]);
    }

    // Extract sizes of the distinct kingdoms
    vector<int> comp_sizes;
    for (int i = 1; i <= N; ++i) {
        if (dsu.parent[i] == i) {
            comp_sizes.push_back(dsu.size[i]);
        }
    }

    // Sort kingdom sizes and populations in descending order
    sort(comp_sizes.rbegin(), comp_sizes.rend());
    sort(A.rbegin(), A.rend());

    long long total_power = 0;
    int pointer = 0;

    long long MOD = 998244353;
    long long inv2 = 499122177; // Modular inverse of 2 modulo 998244353

    // Assign the largest populations to the largest kingdoms
    for (int c : comp_sizes) {
        long long sum = 0;
        for (int i = 0; i < c; ++i) {
            sum = (sum + A[pointer]) % MOD;
            pointer++;
        }

        // Number of friendship pairs: (Sum * (Sum - 1)) / 2 % MOD
        long long pairs = (sum * (sum - 1 + MOD) % MOD) * inv2 % MOD;
        total_power = (total_power + pairs) % MOD;
    }

    return static_cast<int>(total_power);
}

// ---------------------------------------------------------
// Boilerplate main function for custom testing
// ---------------------------------------------------------
//

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

int main() {
    // Fast I/O
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    setIO("check");
    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> roads(M, vector<int>(2));
        for (int i = 0; i < M; ++i) {
            cin >> roads[i][0] >> roads[i][1];
        }

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        cout << maxFriendshipPower(N, M, roads, A) << "\n";
    }

    return 0;
}

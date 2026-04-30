#include <bits/stdc++.h>
using namespace std;

// ===== Wrapper types exactly as in the screenshots =====
struct InputData {
    // Undirected edges (u, v)
    vector<pair<int,int>> connections;
    // Seedable users and their costs; users absent here are NOT seedable
    map<int,int> costs;
    // User values keyed by user id (1..n)
    map<int,int> values;
    // Total budget and maximum influence depth
    int budget;
    int depth;
    // Preserve insertion order of potential seeds for deterministic ties
    vector<int> seed_order;
};

// ===== readInput(): conforms to the provided format =====
InputData readInput() {
    InputData data;

    // Read number of users
    int n;
    cin >> n;

    // Read number of connections
    int num_connections;
    cin >> num_connections;

    // Read connections (undirected)
    for (int i = 0; i < num_connections; i++) {
        int u, v;
        cin >> u >> v;
        data.connections.push_back({u, v});
    }

    // Read number of potential seeds
    int num_seeds;
    cin >> num_seeds;

    // Read potential seeds and their costs; keep insertion order
    for (int i = 0; i < num_seeds; i++) {
        int user_id, cost;
        cin >> user_id >> cost;
        data.costs[user_id] = cost;
        data.seed_order.push_back(user_id);
    }

    // Read values for each user (1..n)
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        data.values[i] = value;
    }

    // Read budget and depth (separate lines)
    cin >> data.budget;
    cin >> data.depth;

    return data;
}

// ===== Greedy solver (marginal gain per cost with BFS reach up to depth d) =====
tuple<vector<int>, int, int> solveCampaign(
    const vector<pair<int,int>>& connections,
    const map<int,int>& costs,
    const map<int,int>& values,
    const vector<int>& seed_order,
    int budget,
    int d
) {
    // Determine max user id (n) from values
    int n = 0;
    for (auto &kv : values) n = max(n, kv.first);

    // Build adjacency list for an undirected graph
    vector<vector<int>> adj(n + 1);
    for (auto &e : connections) {
        int u = e.first, v = e.second;
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // Helper BFS to collect nodes within distance d (including the seed itself)
    auto bfsReach = [&](int s) {
        vector<int> res;
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res.push_back(u);
            if (dist[u] == d) continue;
            for (int v : adj[u]) {
                if (v >= 1 && v <= n && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return res;
    };

    // Precompute reach for each candidate seed
    unordered_map<int, vector<int>> reach;
    reach.reserve(seed_order.size() * 2 + 1);
    for (int u : seed_order) {
        reach[u] = bfsReach(u);
    }

    // Fast value lookup
    auto getVal = [&](int u) -> int {
        auto it = values.find(u);
        return (it == values.end() ? 0 : it->second);
    };

    // Selection loop
    vector<int> picked;
    long long total_value = 0;
    long long total_cost  = 0;

    vector<char> in_reached(n + 1, 0); // who is already counted as reached

    // Original insertion order index for deterministic tie‑breaks
    unordered_map<int,int> order_index;
    order_index.reserve(seed_order.size() * 2 + 1);
    for (int i = 0; i < (int)seed_order.size(); ++i) order_index[seed_order[i]] = i;

    vector<char> already_picked(n + 1, 0);

    while (true) {
        int best_seed = -1;
        long long best_gain = 0;
        int best_cost = 0;
        double best_eff = -1.0;

        for (int u : seed_order) {
            if (already_picked[u]) continue;
            auto itc = costs.find(u);
            if (itc == costs.end()) continue; // must be seedable
            int c = itc->second;
            if (c > budget - (int)total_cost) continue;

            // Marginal gain = values of newly reached unique users
            long long gain = 0;
            for (int v : reach[u]) if (!in_reached[v]) gain += getVal(v);
            if (gain <= 0) continue;

            double eff = (double)gain / (double)c;

            if (eff > best_eff + 1e-12 ||
                (fabs(eff - best_eff) <= 1e-12 &&
                 order_index[u] < (best_seed == -1 ? INT_MAX : order_index[best_seed]))) {
                best_seed = u;
                best_gain = gain;
                best_cost = c;
                best_eff  = eff;
            }
        }

        if (best_seed == -1) break;

        // Commit selection
        picked.push_back(best_seed);
        total_cost += best_cost;
        for (int v : reach[best_seed]) {
            if (!in_reached[v]) {
                in_reached[v] = 1;
                total_value += getVal(v);
            }
        }
        already_picked[best_seed] = 1;
    }

    return {picked, (int)total_value, (int)total_cost};
}

// ===== main(): identical output contract to the screenshots =====
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto data = readInput();

    auto result = solveCampaign(
        data.connections,
        data.costs,
        data.values,
        data.seed_order,
        data.budget,
        data.depth
    );

    vector<int> selected_seeds = get<0>(result);
    int total_value = get<1>(result);
    int total_cost  = get<2>(result);

    // Output: seed IDs on one line (space‑separated)
    for (int i = 0; i < (int)selected_seeds.size(); i++) {
        if (i) cout << ' ';
        cout << selected_seeds[i];
    }
    cout << '\n';
    cout << total_value << '\n';
    cout << total_cost << '\n';

    return 0;
}

#include<bits/stdc++.h>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
vi dp(100001, 0);
void dfs(int node, int par, vvi& adj){
    dp[node] = 1;
    for(int nei: adj[node]){
        if(nei == par) continue;
        dfs(nei, node, adj);
        dp[node] += dp[nei];
    }
}

int main() {
    setIO("");
    int n;
    cin >> n;
    if(n % 2 == 1){
        cout << -1 << '\n';
        return 0;
    }
    vvi adj(n + 1);
    for(int i = 0;i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, adj);
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(dp[i] % 2 == 0){
            ans++;
        }
    }
    cout << ans - 1 << '\n';
    return 0;
}

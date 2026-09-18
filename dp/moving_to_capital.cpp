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

void dfs(int node, vvi& adj, vector<bool> &vis, vi&dist, vi& dp){
    if(vis[node]) return;
    vis[node] = true;
    for(int nei: adj[node]){
        if(!vis[nei] && dist[node] < dist[nei]){
            dfs(nei, adj, vis, dist, dp);
        }
        if(dist[node] >= dist[nei]){
            // ans = dfs(nei, adj, vis, dist, dp);
            dp[node] = min(dp[node], dist[nei]);
        }
        else dp[node] = min(dp[nei], dp[node]);
    }
    dp[node] = min(dp[node], dist[node]);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    vvi transpose_adj(n + 1);
    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        transpose_adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vi dist(n + 1, -1);
    dist[1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int nei: adj[node]){
            if(dist[nei] == -1){
                q.push(nei);
                dist[nei] = dist[node] + 1;
            }
        }
    }

    // vi ans(n + 1, 0);
    // for(int i = 1;i <= n;i++){
    //     ans[i] = dist[i];
    // }
    vector<bool> vis(n + 1, false);
    vi dp(n + 1, INT_MAX);
    dp[1] = 0;
    dfs(1, adj, vis, dist, dp);
    // while(!nq.empty()){
    //     int node = nq.front();

    // }
    for (int i = 1;i <= n; i++) {
        cout << dp[i] << ' ';
    }
    cout<< endl;
}

int main() {
    setIO();

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

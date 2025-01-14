#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, int &c, int n){
    c++;
    vis[node] = true;

    for(int i = 0;i < n;i++){
        if(adj[node][i] && !vis[i]){
            dfs(i, adj, vis, c, n);
        }
    }
}

void solve(int n, int m){
    vector<vector<int>> adj(n, vector<int> (n, 0)); // Adj Matrix

    vector<vector<int>> edges(m, vector<int> (2, 0));

    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }


    for(int i = 0;i < m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][v] = false;
        adj[v][u] = false;
        vector<bool> vis(n, false);
        int c = 0;

        dfs(0, adj, vis, c, n);

        if(c < n){cout << "YES\n"; return;}

        adj[u][v] = true;
        adj[v][u] = true;
    }
    cout << "NO\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    while(cin >> n >> m && !(!n && !m)) solve(n, m);

    return 0;
}
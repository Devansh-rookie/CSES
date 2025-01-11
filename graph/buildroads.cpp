#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;


void dfs(int node, vector<bool> &vis, vector<vector<ll>>&adj){
    if(vis[node]) return;
    vis[node] = true;
    for(ll nei: adj[node]){
        dfs(nei, vis, adj);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >>n >> m;
    vector<vector<ll>> adj(n+1);

    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pll> ans;
    vector<bool> vis(n+1, false);
    dfs(1, vis, adj);
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            ans.emplace_back(1, i); 
            dfs(i, vis, adj);
        }
        // as we have just found a disconnected component we just need to connect it to one of the things it can be any constant or the last value of that dfs search otherise just make a constant c like 1 here which is behaving like a capital, all roads lead to 1 instead of Rome now :smile
    }

    cout << ans.size() << endl;

    for(pll p: ans){
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
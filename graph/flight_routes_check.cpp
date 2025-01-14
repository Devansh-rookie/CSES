#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;
    for(int i : adj[node]){
        if(!vis[i]) dfs(i, adj, vis);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> out(n+1, 0);
    vector<int> in(n+1, 0);

    for(int i =0;i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        out[u]++;
        in[v]++;
    }

    for(int i = 1;i <= n;i++){
        if(!out[i]){
            cout << "NO\n";
            cout << i << ' ' << ((i != 1) ? 1 : i-1) << endl;
            return 0;
        }
        else if(!in[i]){
            cout << "NO\n";
            cout << ((i != 1) ? 1 : i-1) << ' ' << i << endl;
            return 0;
        }
    }


    // for(int i = 1;i <= n;i++){
    //     vector<bool> vis(n+1, false);
    //     dfs(i, adj, vis);


    // }
    int currI = 0;
    int currVal = INT_MAX;

    for(int i =1;i <= n;i++){
        if(out[i] <= currVal){
            currVal = out[i];
            currI = i;
        }
    }

    vector<bool> vis(n+1, false);

    dfs(currI, adj, vis);

    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            cout << "NO\n";
            cout << currI << ' ' << i << '\n';
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
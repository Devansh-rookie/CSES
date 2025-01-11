#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<set<int>> &adj, vector<bool> &vis){
    vis[node] = true;

    for(int i: adj[node]){
        if(!vis[i]){
            dfs(i, adj, vis);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("closing.in");
    ofstream fout("closing.out");

    int n, m;
    fin >> n >> m;

    vector<set<int>> adj(n+1);

    for(int i = 0;i < m;i++){
        int u, v;
        fin >>u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<bool> removed(n+1, false);
    set<int> rset;

    for(int i = 0;i < n;i++){
        int node = 0;
        fin >> node;
        vector<bool> vis(n+1, false);

        int ss = 0;

        for(int i = 1;i <= n;i++){
            if(!removed[i]){
                ss = i;
                break;
            }
        }

        dfs(ss, adj, vis);

        for(int i = 1;i <= n;i++){
            if(!vis[i] && rset.find(i) == rset.end()){
                fout << "NO" << endl;
                ss = 0;
                break;
            }
        }

        if(ss) fout << "YES" << endl;

        removed[node] = true;
        rset.insert(node);

        adj[node].clear();

        for(int i = 1;i <= n;i++){
            if(adj[i].find(node) != adj[i].end()) adj[i].erase(node);
        }

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool dfs(vvi &adj, vi &color, int node, int col){
    color[node] = col;
    bool some = true;
    for(int i : adj[node]){
        if(color[i] == -1){
            some = dfs(adj, color, i, !col);
        }
        else{
            if(color[i] == col){
                return false; 
            }
        }
    }
    return some;
}

int main() {
    setIO("");

    long long n;
    cin >> n;

    vvi adj(n+1);

    for(long long i =0 ;i < n-1;i++){
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi color(n+1, -1);

    bool bipar = dfs(adj, color, 1, 0);

    if(!bipar){
        cout << "0";
        return 0;
    }

    long long color1 = 0;
    long long color2 = 0;

    long long edges_used = n - 1; // since its a tree n-1 edges for n nodes have already been used so from total color1 nodes mul by color2 nodes this would be subtracted

    for(int i = 1;i <= n;i++){
        if(color[i] == 0) color1++;
        else color2++;
    }

    cout << (long long)color1*color2 - edges_used;

    return 0;
}
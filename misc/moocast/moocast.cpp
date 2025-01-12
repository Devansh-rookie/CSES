#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>&adj, vector<bool> &vis, int &running){
    vis[node] = true;
    running++;

    for(int i: adj[node]){
        if(!vis[i]){
            dfs(i, adj, vis, running);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    int n;
    fin >> n;

    vector<vector<int>> input(n);

    for(int i = 0;i < n;i++){
        int x, y, p;
        fin >> x >> y >> p;
        input[i] = {x, y, p};
    }

    vector<vector<int>> adj(n);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j) continue;
            int x1 = input[i][0];
            int y1 = input[i][1];
            int x2 = input[j][0];
            int y2 = input[j][1];
            int p = input[i][2];
            int dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            if(dist <= p*p){
                adj[i].push_back(j);
            }
        }
    }


    int ans = 0;

    for(int i = 0;i < n;i++){
        vector<bool> vis(n, false);
        int running = 0;
        dfs(i, adj, vis, running);
        ans = max(ans, running);
    }

    fout << ans;

    return 0;
}
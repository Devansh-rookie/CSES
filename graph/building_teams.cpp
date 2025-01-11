#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &graph, int node, vector<int> &color, int col){
        color[node] = col;
        bool ans = true;
        for(int nei : graph[node]){
            if(color[nei] != -1){
                if(color[nei] == col){
                    return false;
                }
            }
            else{
                ans = dfs(graph, nei, color, !col);
            }
        }
        return ans;
    }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int n = graph.size();
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> color(n+1, -1);

    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // bool ans = true;
    for(int i = 0;i < n;i++) {
        if(color[i] == -1){
            bool val = dfs(graph, i, color,0);
            if(!val){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }    
        }
    }

    for(int i = 1;i <= n;i++){
        cout << color[i] + 1 << ' ';
    }

    return 0;
}
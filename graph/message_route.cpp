#include<bits/stdc++.h>
#include <climits>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using vi = vector<int>;
using ll = long long;
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    // setIO("check");

    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vi dist(n + 1, INT_MAX);
    vi parent(n + 1);
    iota(all(parent), 0);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int nei: adj[node]){
            if(dist[nei] == INT_MAX){
                dist[nei] = dist[node] + 1;
                parent[nei] = node;
                q.push(nei);
            }
        }
    }

    if(dist[n] == INT_MAX){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    cout << dist[n] + 1 << '\n';
    int node = n;
    vi ans;
    while(parent[node] != node){
        ans.pb(node);
        node = parent[node];
    }
    cout << 1 << ' ';
    for(int i = ans.size() - 1;i >= 0;i--){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}

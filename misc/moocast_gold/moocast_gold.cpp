#include<bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;

class DSU{
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent.resize(n, 0);
        size.resize(n, 1);

        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void uniteSize(int n1, int n2){
        int u, v;
        u = findPar(n1);
        v = findPar(n2);
        if(u == v) return;
        else if(size[u] < size[v]){
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u] += size[v];
        }
    }
};


void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("moocast");
    int n;
    cin >> n;

    vvi edges(n, vi(2, 0));

    for(int i = 0;i < n;i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    // node name would be the index on the edges;

    vvi allConnections;

    for(int i = 0;i < n;i++){
        for(int j = i+1; j < n;j++){
            int x1 = edges[i][0];
            int y1 = edges[i][1];
            int x2 = edges[j][0];
            int y2 = edges[j][1];
            int dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
            allConnections.push_back({dist, i, j});
        }
    }

    sort(allConnections.begin(), allConnections.end());
    int all = allConnections.size();
    DSU ds = DSU(n);

    long long ans = 0;

    for(int i = 0;i < all;i++){
        int w = allConnections[i][0];
        int x = allConnections[i][1];
        int y = allConnections[i][2];
        if(ds.findPar(x) != ds.findPar(y)){
            // ans += (w);
            ans = max(ans, (long long)w);
            ds.uniteSize(x, y);
        }
    }

    cout << ans;

    return 0;
}
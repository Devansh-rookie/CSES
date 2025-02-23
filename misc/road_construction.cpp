#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

class DSU {
    public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n+1, 0);
        size.resize(n+1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }

    void uniteSize(int n1, int n2) {
        int u, v;
        u = findPar(n1);
        v = findPar(n2);
        if (u == v) return;
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

// nobody cares about you, whenever around RP Trust issues

int main() {
    setIO("check");

    int n, m;
    cin >> n >> m;
    int connected_comp = n;

    DSU ds = DSU(n);
    int maxx = INT_MIN;

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        if(ds.findPar(a) != ds.findPar(b)){
            connected_comp--;
        }
        ds.uniteSize(a, b);
        int root = ds.findPar(a);
        maxx = max(maxx, ds.size[root]);
        cout << connected_comp << ' '<< maxx << '\n';
    }


    return 0;
}


// About 1-2
// Abstract 3
// Motivation 4
// Literature Review 5-6
// Methodology 7-8
// F&T 9-10
// Ref 11

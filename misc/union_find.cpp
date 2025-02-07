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

        for (int i = 0; i < n; i++) {
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

int main() {
    // setIO("check");

    int n, q;
    cin >> n >>q;

    DSU ds = DSU(n);

    for(int i = 0;i < q;i++){
        vector<int> aa(3);
        cin >> aa[0] >> aa[1] >> aa[2];

        if(!aa[0]){
            ds.uniteSize(aa[1], aa[2]);
        }
        else{
            cout << (ds.findPar(aa[1])==ds.findPar(aa[2])) << '\n';
        }
    }

    return 0;
}

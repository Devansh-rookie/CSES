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
    int num = 0;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
        num = n;
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }

    void uniteSize(int n1, int n2) {
        int u = findPar(n1);
        int v = findPar(n2);
        if (u == v) return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
        num--;
    }
};


int main() {
    // setIO("check");

    int n;
    cin >> n;

    DSU ds = DSU(n);


    // vector<int> arr(n);

    for(int i = 0;i < n;i++){
        int u;
        int v = i + 1;
        cin >> u;
        ds.uniteSize(u, v);
    }

    cout << ds.num << endl;

    return 0;
}

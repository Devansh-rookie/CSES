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

void solve(){
    int n, m1 ,m2;
    cin >> n >> m1 >> m2;

    // F first then G

    vector<set<int>> f(n+1);
    vector<set<int>> g(n+1);
    vector<set<int>> dg(n+1);

    for(int i = 0;i < m1;i++){
        int u, v;
        cin >> u >> v;
        f[v].insert(u);
        f[u].insert(v);
    }
    for(int i = 0;i < m2;i++){
        int u, v;
        cin >> u >> v;
        g[v].insert(u);
        g[u].insert(v);
        dg[u].insert(v);
    }

    long long ans = 0;

    for(int i = 1;i <= n;i++){
        set<int> del;
        for(int nei : f[i]){
            if(g[i].find(nei) == g[i].end()){
                ans++;
                // f[i].erase(nei);
                del.insert(nei);
                f[nei].erase(i);
            }
        }
        for(int j : del){
            f[i].erase(j);
        }
    }

    int add = 0;

    for(int i = 1;i <= n;i++){
        for(int nei : g[i]){
            add += (long long)(g[i].size() - f[i].size());
        }
    }

    cout << ans + add/2<< endl;
}

int main() {
    setIO("check");

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

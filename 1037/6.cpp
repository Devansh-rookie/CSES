#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("check");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<ll> color(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> color[i];
        }
        vector<vector<pair<ll,ll>>> adj(n+1);
        vector<tuple<ll,ll,ll>> ed;
        ed.assign(n-1, {});
        for (int i = 0; i < n-1; i++) {
            ll u, v;
            ll c;
            cin >> u >> v >> c;
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
            ed.emplace_back(u, v, c);
        }
        int B = max(1, (int)(sqrt(2.0*(n-1))));
        vector<bool> ish(n+1, false);
        for (int i = 1; i <= n; i++) {
            if ((int)adj[i].size() > B) {
                ish[i] = true;
            }
        }
        vector<ll> totw(n+1, 0);
        vector<unordered_map<int,ll>> wsum(n+1);
        for (int i = 1; i <= n; i++) {
            if (!ish[i]) continue;
            auto &mp = wsum[i];
            mp.reserve(adj[i].size()*2);
            for (auto &pr : adj[i]) {
                int u = pr.first;
                ll w = pr.second;
                totw[i] += w;
                mp[color[u]] += w;
            }
        }
        vector<vector<pair<int,ll>>> hnei(n+1);
        for (int v = 1; v <= n; v++) {
            for (auto &pr : adj[v]) {
                int u = pr.first;
                ll w = pr.second;
                if (ish[u]) hnei[v].emplace_back(u, w);
            }
        }
        ll total = 0;
        for (auto &e:ed) {
            int u, v;
            ll w;
            tie(u,v,w) = e;
            if (color[u] != color[v]) total += w;
        }
        while (q--) {
            int v, x;
            cin >> v >> x;
            int old = color[v];
            int ne = x;
            if (old == ne) {
                cout << total << '\n';
                continue;
            }
            for (auto &pr : hnei[v]) {
                int h = pr.first;
                ll w = pr.second;
                auto &mp = wsum[h];
                mp[old] -= w;
                mp[ne] += w;
            }
            if (!ish[v]) {
                for (auto &pr : adj[v]) {
                    int u = pr.first;
                    ll w = pr.second;
                    ll was = (old == color[u] ? 0 : w);
                    ll now = (ne==color[u] ? 0 : w);
                    total += (now- was);
                }
            } else {
                ll lose = wsum[v][old];
                ll gain = wsum[v][ne];
                total+= (lose - gain);
            }
            color[v] = ne;
            cout << total << '\n';
        }
    }
    return 0;
}

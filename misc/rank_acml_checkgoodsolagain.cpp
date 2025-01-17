#include<bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
set<int> ans;

void dfs(int node, vvi &adj, int curr, vb & vis){ 
    vis[node] = true;
    if(node == curr){
        ans.insert(node);
        return;
    }
    for(int child: adj[node]){
        if(!vis[child]){
            dfs(child, adj, curr, vis);
        }
    }
}

int main() {
    setIO();

    int n, k;

    cin >> n >> k;

    vvi adj(n+1);

    for(int i = 0;i < k;i++){
        int u, v, su, sv;
        cin >> u >> v>> su >> sv;
        if(su > sv){
            adj[u].push_back(v);
        }
        else adj[v].push_back(u);
    }

    for(int i = 1;i <= n;i++){
        // for(int o = 0;o <=n;o++) vis[i] = 0;
        vb vis(n+1, false);
        for(int j: adj[i]) dfs(j, adj, i, vis);
    }

    cout << ans.size();

    return 0;
}


/*
// good solution do later again

#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<int> adj[10001];
vector<int> disc, low, inStack;
stack<int> st;
set<int> result;
int timer;

void tarjanSCC(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjanSCC(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        vector<int> scc;
        while (true) {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            scc.push_back(v);
            if (u == v) break;
        }
        if (scc.size() > 1) {
            for (int player : scc) {
                result.insert(player);
            }
        }
    }
}

int main() {
    setIO();

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int u, v, su, sv;
        cin >> u >> v >> su >> sv;
        if (su > sv) {
            adj[u].push_back(v);
        } else {
            adj[v].push_back(u);
        }
    }

    disc.assign(n + 1, -1);
    low.assign(n + 1, -1);
    inStack.assign(n + 1, false);
    timer = 0;

    for (int i = 1; i <= n; i++) {
        if (disc[i] == -1) {
            tarjanSCC(i);
        }
    }

    cout << result.size() << endl;

    return 0;
}

*/
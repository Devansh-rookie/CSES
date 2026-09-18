#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vll = vector<ll>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void print(set<int> a, set<int> b){
    cout << "Set A: ";
    for(auto x : a){
        cout << x << " ";
    }
    cout << "\nSet B: ";
    for(auto x : b){
        cout << x << " ";
    }
    cout << "\n";

}

vi color;
bool bfs(int node, vvi &adj){
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int nei: adj[front]){
            if(color[nei] == -1){
                color[nei] = !color[front];
                q.push(nei);
            }
            if(color[nei] == color[front]){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    set<int> a, b;
    int n;
    cin >> n;
    vvi adj(n + 1);
    color.assign(n + 1, -1);
    vi cnt(n + 1, 0);
    bool cancel = false;
    for(int i = 0;i < n;i++){
        int x, y;
        cin >> x >> y;
        if(x == y){
            cancel = true;
        }
        cnt[x]++;
        cnt[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(cancel){
        cout << "NO\n";
        return;
    }
    for(int i = 1;i <= n;i++){
        if(cnt[i] > 2){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 1;i <= n;i++){
        if(color[i] == -1){
            bool bipartite = bfs(i, adj);
            if(!bipartite){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    setIO("");

    int t;
    cin >> t;
    while(t--){
        solve();
        color.clear();
    }

    return 0;
}

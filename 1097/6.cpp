#include <bits/stdc++.h>
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
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    vector<vector<int>> add_at(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        add_at[a[i]].push_back(i);
    }
    set<int> pool;
    vector<int> head(n + 1);
    vector<int> tail(n + 1);
    vector<int> for_ans(n + 1, 0); 
    for(int i = 1; i <= n; i++){
        head[i] = i;
        tail[i] = i;
    }
    for(int k = 1; k <= n; k++){
        for(int i : add_at[k]){
            pool.insert(i);
        }

        if(pool.empty()){
            cout << "No\n";
            return;
        }
        int bomb = (k < n)?tail[k+1]:-1;
        int u = -1;
        if(bomb != -1 && pool.count(bomb)){
            u = bomb;
        } 
        else {
            auto it = pool.begin();
            if(k < n && head[*it] == k){
                it++; 
            }
            if(it != pool.end()){
                u = *it;
            }
        }
        if(u == -1){
            cout << "No\n";
            return;
        }
        pool.erase(u);
        for_ans[u] = k;
        int start = head[u];
        int end = tail[k];
        head[end] = start;
        tail[start] = end;
    }
    
    cout << "YES\n";
    int curr = 1;
    for(int i = 1; i <= n; i++){
        cout << curr << (i == n ? "" : " ");
        curr = for_ans[curr];
    }
    cout << "\n";
}

int main() {
    setIO();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
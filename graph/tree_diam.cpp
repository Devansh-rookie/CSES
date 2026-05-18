#include<bits/stdc++.h>
#include <future>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int ans = 0;
int solve(vector<vector<int>> &adj, int node, int parent){
    int max1 = 0, max2 = 0;
    for(int nei: adj[node]){
        if(parent == nei) continue;
        int d = 1 + solve(adj, nei, node); // solve basically gets the depth

        if(d > max1){
            max2 = max1;
            max1 = d;
        }
        else if(d > max2){// here max1 is bigger than d but max2 is smaller
            max2 = d;
        }
    }
    ans = max(ans, max1 + max2);
    return max1;
}


int main() {
    // setIO("check");
    async();
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for(int i = 0;i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve(adj, 1, 0);
    cout << ans;

    return 0;
}

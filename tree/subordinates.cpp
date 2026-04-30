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

int dfs(vector<int> &dp, vector<vector<int>> &adj, int node){
    if(dp[node] != -1) return dp[node];
    int val = 0;
    for(int i: adj[node]){
        val += 1 + dfs(dp, adj, i);
    }
    return dp[node] = val;
}

int main() {
    // setIO("check");
    int n;
    cin >> n;
    vector<int> arr(n+1, 0);

    for(int i = 2;i <= n;i++){
        cin >> arr[i];
    }

    vector<int> dp(n+1, -1);
    vector<vector<int>> adj(n+1, vector<int>());

    for(int i = 2;i <= n;i++){
        adj[arr[i]].push_back(i);
    }

    dfs(dp, adj, 1);

    for(int i = 1;i <= n;i++){
        cout << dp[i] << " ";
    }

    return 0;
}

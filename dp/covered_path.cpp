#include<bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
#define nl '\n'
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<vector<int>> dp;

int solve(int v, int v2, int t, int dmax, int tmax){
    if(t == tmax && v == v2) return v;
    if(t == tmax && v != v2) return INT_MIN;
    if(dp[v][t] != -1) return dp[v][t];
    int state_ans = INT_MIN;
    for(int d = -dmax;d <= dmax;d++){
        int next_state = solve(max(0, v + d), v2, t + 1, dmax, tmax);
        if(next_state != INT_MIN) {
            state_ans = max(state_ans, v + next_state);
        }
    }
    return dp[v][t] = state_ans;
}

int main() {
    setIO();
    int v1, v2;
    int t, d;
    cin >> v1 >> v2;
    cin >> t >> d;
    dp.assign(max(v1, v2) + d*t + 1, vector<int>(t + 1, -1));
    cout << solve(v1, v2, 1, d, t) << nl;
    return 0;
}

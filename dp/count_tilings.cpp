#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<vector<ll>> dp;
int MOD = 1e9 + 7;
int N, M;
int temp;
// we fill cloumns and start by each emplty bitmask and check
void fillColumns(int row, int col, int mask, int nextMask){
    if(row == N){
        dp[col + 1][nextMask] = (dp[col + 1][nextMask] + dp[col][temp])%MOD;
        return;
    }

    if(mask & (1 << row)){
        fillColumns(row + 1, col, mask, nextMask);
        return;
    }

    // horizontal
    if(col + 1 < M){
        fillColumns(row + 1, col, mask | 1 << row, nextMask | 1 << row);
    }

    // vertical
    if(row + 1 < N && (!(mask & (1 << (row+1))))){
        fillColumns(row + 2, col, mask | 1 << row | 1 << (row + 1), nextMask);
    }
}

int main() {
    // setIO("check");
    int n, m;
    cin >> n >> m;
    N = n;
    M = m;
    dp.assign(m+1, vector<ll>(1<<n, 0));
    dp[0][0] = 1;
    for(int c = 0;c < m;c++){
        for(int mask = 0;mask < 1 << n; mask++){
            if(dp[c][mask] == 0) continue;
            temp = mask;
            fillColumns(0, c, mask, 0); // next is zero because we didn't add anything yet
        }
    }
    cout << dp[m][0] << endl;
    return 0;
}

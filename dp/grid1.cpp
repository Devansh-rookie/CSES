#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const vector<pair<int, int>> directions = {{1, 0}, {0, 1}};
int n;
vector<vector<int>> arr;
vector<vector<int>> dp;
bool check(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= n){
        return false;
    }
    return true;
}
int solve(int i, int j){
    if(i == n - 1 && j == n - 1){
        return arr[i][j];
    }
    if(!check(i, j)) return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = 0;
    for(const auto &[vx, vy]: directions){
        int nx = i + vx;
        int ny = j + vy;
        if(check(nx, ny) && arr[nx][ny]){
            ans = (ans%MOD + (solve(nx, ny)%MOD))%MOD;
        }
    }
    return dp[i][j] = ans;
}

int main() {
    // setIO("check");

    cin >> n;

    arr.assign(n, vector<int> (n, 1));
    dp.assign(n, vector<int> (n, -1));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            char c;
            cin >> c;
            if(c == '*'){
                arr[i][j] = 0;
            }
        }
    }

    if(!arr[0][0]){
        cout << 0;
        return 0;
    }

    cout << solve(0, 0);

    return 0;
}

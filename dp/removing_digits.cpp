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

vector<int> dp(1e6+1, -1);
int solve(int n){
    if(n == 0) return 0;
    if(n/10 == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int ans = 1e7;
    int old = n;
    while(n != 0){
        int d = n%10;
        if(!d) {n = n/10;continue;}
        ans = min(ans, 1 + solve(old - d));
        n = n/10;
    }
    return dp[old] = ans;
}

int main() {
    // setIO("check");
    int n;
    cin >> n;
    int ans = solve(n);
    cout << ans;
    return 0;
}

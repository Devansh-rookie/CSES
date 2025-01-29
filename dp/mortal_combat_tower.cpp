#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
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

    vi arr = vi(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];

    vvi dp = vvi(n+1, vi(2, 1e8));
    // here 1 would be my friend and 0 would be me

    // here the next is of 0'th player, if its written dp[0][0] for 0th index 0th player has to play next 1st has played and 0 was the min skips
    dp[0][0] = 0;
    for(int i = 0;i < n;i++){
        // (second val)add the skips to it to get there if we are coming from the friends branch otherwise take it directly(first val)
        dp[i+1][1] = min(dp[i+1][1], arr[i] + dp[i][0]);
        if(i + 2 <= n) 
            dp[i+2][1] = min(dp[i+2][1], arr[i+1] + arr[i] + dp[i][0]);
        // here directly go or come from my branch
        dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
        if(i + 2 <= n) dp[i+2][0] = min(dp[i+2][0], dp[i][1]);
    }

    cout << min(dp[n][0], dp[n][1]) << endl;
}

int main() {
    // setIO("check");

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
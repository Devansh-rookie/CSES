#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// predict future states using the current states
void push_dp(){
    int n;
    cin >> n;

    vi arr = vi(n, 0);
    for(int i =0;i < n;i++) cin>> arr[i];
    vi dp = vi(n+1, INT_MAX);
    dp[0] = 0; // base case already on 0
    for(int i = 0;i < n-1;i++){
        dp[i+1] = min(dp[i+1], dp[i] + abs(arr[i] - arr[i+1]));
        if(i + 2 < n) 
            dp[i+2] = min(dp[i+2], dp[i] + abs(arr[i] - arr[i+2]));
    }
    cout << dp[n-1];
}

// predict the current states using the previous states
void pull_dp(){
    int n;
    cin >> n;

    vi arr = vi(n, 0);

    for(int i =0;i < n;i++) cin>> arr[i];
    vi dp = vi(n, 0);
    for(int i = 1;i < n;i++){
        dp[i] = min(
            dp[i-1] + abs(arr[i] - arr[i-1]), 
            (i>=2)?(dp[i-2] + abs(arr[i]- arr[i-2])):INT_MAX
        );
    }
    cout << dp[n-1];
}

int main() {
    // setIO("check");
    push_dp();
    return 0;
}
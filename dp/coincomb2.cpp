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
const int MOD = (int)1e9+7;
int main() {
    // setIO("check");

    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
        
    vector<long long> dp(target+2, 0);

    // sort(arr.begin(), arr.end());

    dp[0] = 1;
    for(int j = 0 ;j < n;j++){
        // each coin will build stuff in an ordered fashion
        for(int i = 1;i <= target;i++){
            if(arr[j] <= i){
                dp[i] = (dp[i] + dp[i - arr[j]])%MOD;
            }
        }
    }

    cout << dp[target]%MOD <<endl;

    return 0;
}


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
 
int main() {
    // setIO("check");
 
    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
        
    vector<int> dp(target+2, 1e7);
 
    dp[0] = 0;
    int mini = INT_MAX;
    for(int i = 0;i < n;i++){
        if(arr[i] <= target) dp[arr[i]] = 1;
        mini = min(mini, arr[i]);
    }
// cout <<123;
    if(mini > target){
        cout << -1;
        return 0;
    }
 
    for(int i = 1;i <= target;i++){
        for(int j = 0;j < n;j++){
            if(arr[j] <= i){
                dp[i] = min(dp[i], dp[i - arr[j]]+1);
            }
        }
    }
 
    if(dp[target] >= 1e7){
        cout << -1;
        return 0;
    }
 
    cout << dp[target] <<endl;
 
    return 0;
}
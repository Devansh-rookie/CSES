#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int mod = 998244353;
int main(){
    int n, k;
    cin >> n >> k;
    vector<pii> ranges(k);
    // set<int> s;
    for(int i = 0;i < k;i++){
        int l, r;
        cin >> l >> r;
        ranges[i].first = l;
        ranges[i].second = r;
    }
    
    // here make a DP array which stores how many ways are there to reach 'i' you can always reach 0 in 1 way and the DP array would be a contiguous difference array in which we will sum with the for loop
    vector<long long> dp(n+2, 0);
    dp[0] = 1;// using 0 indexed as the person in question was standing on 1 here he will stand on 1
    dp[1] = -1; //using difference array
    for(int i = 0;i < n;i++){
        if(i > 0) dp[i] = (dp[i] + dp[i-1])%mod;//convert from difference form to actual form
        for(int j = 0;j < k;j++){
            int l = ranges[j].first;
            int r = ranges[j].second;

            // continue to difference form
            // here we can say there are atleast dp[i] ways when not in difference form to reach i + l thats why this form
            if(i + l <= n) dp[i + l] = (dp[i + l]%mod + dp[i])%mod;
            if(i + r <= n) dp[i + r + 1] = (dp[i + r + 1]%mod - dp[i])%mod;
        }
    }
    long long ans = 0;
    ans = (dp[n-1]+mod)%mod; // 0 indexed thats why n-1 as here we go from 0 to n-1 instead of 1 to n
    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
using pii = pair<int, int>;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// int states(int i, bool take, int n, int x){
//     if(i >= n) return 0;

//     return ;
// }

int main() {
    setIO("check");

    int n, x;
    cin >> n >> x;
    vector<int> weights(n, 0);
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // vector<bool> ridden(n, 0); // a bit mask would be better as suspecteda bitmask DP thing to traverse all possible combinations of the people
    // int had_to_ride = n;
    for(int i = 0;i < n;i++) cin >> weights[i];
    if(*min_element(weights.begin(), weights.end()) > x){
        cout << "Wrong Weigts";
        return 0;
    }
    int all_states = (1 << n);
    vector<pii> dp(all_states, {INT_MAX, -1});
    dp[0] = make_pair(1, 0);
    // it would be current state and weights in current ride then we gotta add a number to it once we exceed x in that and increae the ride and set the weight to 0
    for(int mask = 0;mask < all_states; mask++){
        for(int i = 0;i < n;i++){
            if(!(mask & 1 << i)){
                pii candidate;
                if(weights[i] + dp[mask].second > x){
                    candidate = {
                        dp[mask].first + 1, weights[i]
                    };
                }
                else{
                    candidate = {
                        dp[mask].first, dp[mask].second + weights[i]
                    };
                }
                int newState = mask | (1 << i);
                if(dp[newState].first > candidate.first || (candidate.first == dp[newState].first && candidate.second < dp[newState].second)){
                    dp[newState] = candidate;
                }
            }
        }
    }

    cout << dp[all_states - 1].first << endl;

    return 0;
}

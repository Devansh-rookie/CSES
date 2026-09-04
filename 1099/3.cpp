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

int main(){
    // setIO("check");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    vector<pair<ll, int>> state;

    state.reserve(6000000); 

    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n, 0);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        state.clear();
        for(int i = 0; i < n; i++){
            ll curr = arr[i];
            int steps = 0;
            
            while(curr > 2){
                state.push_back({curr, steps});
                if(curr % 2 == 0){
                    curr /= 2;
                }
                else{
                    curr++;
                }
                steps++;
            }
            if(curr == 2){
                state.push_back({2, steps});
                state.push_back({1, steps + 1});
            } 
            else if(curr == 1){
                state.push_back({1, steps});
                state.push_back({2, steps + 1});
            }
        }
        sort(state.begin(), state.end());
        ll ans = -1;
        ll val = -1;
        int count = 0;
        ll cost = 0;
        for (auto const& state : state) {
            if (state.first != val) {
                if (count == n) {
                    if (ans == -1 || cost < ans) {
                        ans = cost;
                    }
                }
                val = state.first;
                count = 1;
                cost = state.second;
            } 
            else{
                count++;
                cost += state.second;
            }
        }

        if (count == n) {
            if (ans == -1 || cost < ans) {
                ans = cost;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}
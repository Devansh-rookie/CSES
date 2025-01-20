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

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> x(n);
        map<int, int> m;
        for(int i = 0; i < n;i++){
            cin >> x[i];
            m[x[i]]++;
        }

        int ans = 0;
        for(const auto&[num, count]:m){
            int opp = k - num;
            if(m.count(opp)){
                if(opp == num){
                    ans += m[num]/2;
                } 
                else if(m[num] > 0 && m[opp] > 0){
                    int pairs = min(m[num], m[opp]);
                    ans += pairs;
                    m[num] -= pairs;
                    m[opp] -= pairs;
                }
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    // setIO("check");
    solve();
    return 0;
}
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
int main() {
    // setIO("check");
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        vector<ll> c(n + 2, 0); 
        ll sum_initial = 0;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            sum_initial += (ll)i * a[i];
            c[a[i]]++; 
        }
        
        for(int h = n;h>=1;h--){
            c[h] += c[h+1];
        }
        
        ll sum_final = 0;
        for(int h = 1;h<=n;h++){
            if (c[h] > 0) {
                ll count = c[h];
                sum_final += count*(2LL*n - count + 1) / 2LL;
            }
        }
        
        ll base_dist = sum_final - sum_initial;
        
        ll max_gain = 0;
        for(ll k = 1;k<=n;k++){
            ll gain = k - n + c[a[k]] - 1;
            max_gain = max(max_gain, gain);
        }
        
        cout << base_dist + max_gain << "\n";
    }

    return 0;
}
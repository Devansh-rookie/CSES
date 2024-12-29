#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll something(ll n,ll k){
    ll ans = 0;
            ll l = 1, r = n;
            ll depth = 0;
            ll ogMid = (l+r)/2;
            while (r - l + 1 >= k) {
                ll mid = (l + r) / 2;

                if ((r - l + 1) % 2 == 1) {
                    r = mid - 1;
                    ans += (ll)(ogMid)*pow(2, depth);
                } else {
                    r = mid;
                }
                depth++;
            }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(k == 1) cout << (ll)n*(n+1)/2 << endl;
        else if(n%2 == 1){
            ll ans = 0;
            ll l = 1, r = n;
            ll depth = 0;
            ll ogMid = (l+r)/2;
            while (r - l + 1 >= k) {
                ll mid = (l + r) / 2;

                if ((r - l + 1) % 2 == 1) {
                    r = mid - 1;
                    ans += (ll)(ogMid)*pow(2, depth);
                } else {
                    r = mid;
                }
                depth++;
            }
            cout << ans << '\n';
        }
        else{
            ll ans = 0;
            ll l = 1, r = n;
            ll depth = 0;
            ll ogMid = (l+r)/2;
            while (r - l + 1 >= k && r%2 == 0) {
                ll mid = (l + r) / 2;

                if ((r - l + 1) % 2 == 1) {
                    r = mid - 1;
                    // ans += (ll)(ogMid)*pow(2, depth);
                } else {
                    r = mid;
                }
                depth++;
            }
            ll some = something(r, k);
            ans = (some + (pow(2, depth)-1)*some);
            cout << ans << '\n';
        }
    }
    return 0;
}
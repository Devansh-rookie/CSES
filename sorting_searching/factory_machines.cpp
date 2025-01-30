#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) x.begin(), x.end()
using ll = long long;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll most(vi &arr, ll t, ll maxx){
    ll ans = 0;
    for(int i = 0;i < arr.size();i++){
        ans += (t/(arr[i]));
        // this line is important to prevent overflow and bad /unexpected output
        if(ans >= maxx) return ans;
    }
    return ans;
}

int main() {
    // setIO("check");
    ll n, t;

    cin >> n >> t;

    vi arr = vi(n);
    sort(all(arr));

    for(int i = 0;i < n;i++) cin >>arr[i];
    ll minn = arr[0];
    ll hi = minn * t;
    ll lo = 0;
    ll mid = 0;
    ll ans = LONG_MAX;
    while(lo <= hi){
        // here we can keep lo <= hi as there is mid + 1 and mid -1 if there was even one mid instead of them them it would have been an infinite loop which is not good
        mid = lo +(hi - lo)/2;

        ll some = most(arr, mid, t);

        if(some >= t){
            ans = min(ans, mid);
        }

        if(some >= t){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
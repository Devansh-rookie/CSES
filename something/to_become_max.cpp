#include<bits/stdc++.h>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vll = vector<ll>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n, 0);
    for(int i = 0;i < n;i++) cin >> a[i];

    ll low = 0, high = *max_element(all(a)) + n, ans, mid;
    while(low <= high){ // <= as never low or high - mid always mid + 1 or mid + 1
        bool good = false;
        mid = (high - low)/2 + low;
        for(int i = 0;i < n;i++){
            vll need(n, 0);
            need[i] = mid;
            ll used = 0;
            for(int j = i;j < n;j++){
                if(need[j] <= a[j]){
                    break;
                }
                if(j == n - 1){
                    used = k + 1;
                    break;
                }
                used += need[j] - a[j];
                need[j + 1] = max(0LL, need[j] - 1);
            }
            if(used <= k){
                good = true;
            }
        }
        if(good){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    setIO("");

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

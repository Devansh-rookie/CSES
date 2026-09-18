#include <algorithm>
#include<bits/stdc++.h>
#include <cmath>
#include <locale>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvl = vector<vll>;
#define MAXN 1e12
#define all(x) x.begin(), x.end()

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("");
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vi a(n, 0), b(n, 0);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    vll sub(n, 0);
    ll total_sum = 0;
    for(int i = 0;i < n;i++) {
        sub[i] = abs(b[i] - a[i]);
        total_sum += sub[i];
    }
    ll values = k1 + k2;
    if(values >= total_sum) {
        cout << ((values - total_sum) % 2) << '\n';
        return 0;
    }
    sort(all(sub));
    for(int i = n - 1;i >= 0;i--){
        int val = sub[i];
        // this should be equal to all values in i-- then we need to find all equal then make all of them equal to the first value then number of equals till now and that would just be n - 1 - i + 1 and that is to be multiplied by equal value - next smaller value
        int j = i;
        while(j >= 0 && sub[i] == sub[j]){
            j--;
        }
        int next_val = (j < 0 ? 0 : sub[j]);
        int count = n - 1 - j;
        int to_change = val - next_val;
        ll number_required_to_reduce = 1LL * count * to_change;
        if(values >= number_required_to_reduce){
            for(int k = n - 1;k > j;k--){
                sub[k] -= to_change;
            }
            values -= number_required_to_reduce;
            i = j + 1;
        }
        else{
            // reduce all by the same amount to reduce it most
            int reduce_by = (values)/(count);
            int left = values - reduce_by*(count);
            for(int k = n - 1; k > j; k--){
                sub[k] -= reduce_by;
            }
            for(int k = n - 1; k >= n - left; k--){
                sub[k] -= 1;
            }
            values = 0;
            break;
        }
    }

    // calculate the sum of squares
    ll ans = 0;
    for(int i: sub) ans += 1LL*i*i;
    cout << ans << '\n';
    return 0;
}
